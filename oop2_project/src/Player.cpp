#include "Player.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "FallingState.h"

Player::Player(sf::Vector2f location, Resources::Object object)
	: MovingObject(location, object), m_state(std::make_unique<StandingState>()),
	  m_animation(Resources::instance().animationData(object), AnimationState::Stay, m_sprite, 
		Direction::Stay), m_gameData({ START_LIVES, 0 })
{
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
					   m_sprite.getGlobalBounds().height / 2.f);
	
	m_bubble.setTexture(Resources::instance().get(Resources::Bubble));

	m_bubble.setOrigin(m_bubble.getGlobalBounds().width / 2.f,
					   m_bubble.getGlobalBounds().height / 2.f);

	// Set the initial position of the bubble to match the player's position
	m_bubble.setPosition(getPos());
	
}

void Player::setPlayer(sf::Vector2f location)
{
	m_sprite.setPosition(location);
	m_startPos = location;
	std::cout << m_startPos.x << " " << m_startPos.y << std::endl;
}

void Player::update(sf::Time delta)
{
	if (m_flickering && 
		m_flickerClock.getElapsedTime().asSeconds() >= FLICKERING_DURATION)
	{
		m_flickering = false;
		m_sprite.setColor(sf::Color::White);
		m_state->enter(*this);
	}
	checkIfShotArrow();
	
	m_bubble.setPosition(getPos());
	m_animation.update(delta);
	movePlayer(delta);
	
	m_onWall = false;
}

void Player::checkIfShotArrow()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		setStateAnimation(m_dir, AnimationState::Shoot);
		// If space was not previously pressed, this is the first press
		if (!m_spacePressed)
		{	
			m_spacePressed = true;
			if (m_createBullet.getElapsedTime().asSeconds() > TIME_FOR_CREATE_ARROW)
			{
				m_shotArrow = true;
				m_createBullet.restart(); // Reset the timer after shooting an arrow	
		
			}
		}
	}
	else
	{
		m_spacePressed = false;
	}
}

void Player::draw(sf::RenderWindow& window)
{
	if (m_flickering && 
		m_flickerClock.getElapsedTime().asSeconds() < FLICKERING_DURATION)
	{	
		if (m_sprite.getColor() == sf::Color::Transparent)
			m_sprite.setColor(sf::Color::White);
		else
			m_sprite.setColor(sf::Color::Transparent);
	}

	if (m_invincible)
		window.draw(m_bubble);

	window.draw(m_sprite);
}

void Player::movePlayer(sf::Time delta)
{
	//for the cases we are jumping or going down from a wall
	if (m_jumping || !m_onWall)
	{
		handleInput(RELEASE_DOWN);
	}

	if (m_flickering)
	{
		setStateAnimation(m_dir, AnimationState::Hit);
	}

	if (isOutOfScreenBounds())
	{
		setPos(getPrevLoc());
		handleInput(FALLING_OUT_OF_BOUNDS);
		
	}
	else if (isFallingOffTheScreen())
	{
		reduceLife();
		setPos(m_startPos);
	}
	

	m_prevLocation = getPos();
	m_sprite.move(toVector(m_dir) * delta.asSeconds() * ((float(m_superSpeed) * ADD_SPEED) + SPEED));
}

void Player::updateAnimation(sf::Time delta)
{
	m_animation.update(delta);
}

void Player::handleInput(Input input)
{
	std::unique_ptr<PlayerState> newState = m_state->handleInput(input);
	if (newState)
	{
		m_state = std::move(newState);
		m_state->enter(*this);
	}
}

void Player::setStateAnimation(Direction dir, AnimationState state)
{
	//std::cout << "Setting animation state to " << state << " in direction " << toVector(dir).x <<
	//			" " << toVector(dir).x << std::endl; // for debug
	m_dir = dir;
	m_animation.state(state);
	m_animation.direction(dir);
}

void Player::setGameDate(GameData gameData, int num)
{
	m_gameData[gameData] += num;
}

void Player::reduceLife()
{
	//m_sprite.move(toVector(opposite(m_dir)) * 300.f);
	m_gameData[Lives]--;
}

void Player::setFlickering()
{
	m_flickering = true;
	m_flickerClock.restart();
	m_flickerStartTime = m_flickerClock.getElapsedTime();
}

void Player::hittedByEnemy()
{
	reduceLife();
	setFlickering();
}

const std::vector<int>& Player::getGameData() const
{
	return m_gameData;
}

bool Player::isFallingOffTheScreen() const
{
	return(m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2 > SCREEN_Y_SIZE);
}

bool Player::isOutOfScreenBounds() const
{
	return(m_sprite.getPosition().x - m_sprite.getGlobalBounds().width / 2 < 0 ||
		   m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2 > SCREEN_X_SIZE || 
		   m_sprite.getPosition().y - m_sprite.getGlobalBounds().height / 2 < 0);
}