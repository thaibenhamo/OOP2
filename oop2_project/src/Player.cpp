#include "Player.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "FallingState.h"

Player::Player(const sf::Vector2f& location, const Resources::Object object)
	: MovingObject(location, object), m_state(std::make_unique<StandingState>()),
	  m_animation(Resources::instance().animationData(object),
	  AnimationState::Stay, m_sprite, Direction::Stay), m_gameData({ START_LIVES, 0 })
{
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
					   m_sprite.getGlobalBounds().height / 2.f);

	m_bubble.setTexture(Resources::instance().get(Resources::Bubble));

	m_bubble.setOrigin(m_bubble.getGlobalBounds().width / 2.f,
					   m_bubble.getGlobalBounds().height / 2.f);

	// Set the initial position of the bubble to match the player's position
	m_bubble.setPosition(getPos());	
}

void Player::setPlayer(const sf::Vector2f& location)
{
	m_sprite.setPosition(location);
	m_startPos = location;
}

void Player::update(sf::Time delta)
{
	m_delta1 = delta;

	if (m_flickering && 
		Clock::instance().getflickerPlayerClock().getElapsedTime().asSeconds() >= FLICKERING_DURATION)
	{
		m_flickering = false;
		m_sprite.setColor(sf::Color::White);
		m_state->enter(*this);
	}

	checkIfShotArrow();
	m_animation.update(delta);
	updatePlayerGiftPowers();
	m_bubble.setPosition(getPos());
	movePlayer(delta);	
	m_onWall = false;
}

void Player::updatePlayerGiftPowers()
{
	if (m_superSpeed && 
		Clock::instance().getSpeedGiftClock().getElapsedTime().asSeconds() >= GIFT_DURATION)
	{
		m_superSpeed = false;
	}
	if (m_invincible && 
		Clock::instance().getBubbleGiftClock().getElapsedTime().asSeconds() >= GIFT_DURATION)
	{
		m_invincible = false;
	}
}

void Player::checkIfShotArrow()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// If space was not previously pressed, this is the first press
		if (!m_spacePressed)
		{
			//setStateAnimation(m_dir, AnimationState::Shoot);
			m_spacePressed = true;
			if (Clock::instance().getShootClock().getElapsedTime().asSeconds() > TIME_FOR_CREATE_ARROW || m_first)
			{
				m_first = false;
				m_shotArrow = true;
				Resources::instance().playSound(SoundType::PlayerShoot);
				Clock::instance().getShootClock().restart(); // Reset the timer after shooting an arrow	
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
		Clock::instance().getflickerPlayerClock().getElapsedTime().asSeconds() < FLICKERING_DURATION)
	{
		
		if (m_sprite.getColor() == sf::Color::Transparent)
		{
			m_sprite.setColor(sf::Color::White);
		}	
		else
		{
			m_sprite.setColor(sf::Color::Transparent);
		}		
	}
	if (m_invincible)
	{
		window.draw(m_bubble);
	}
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

void Player::setStateAnimation(const Direction dir, const AnimationState state)
{
	m_dir = dir;
	m_animation.state(state);
	m_animation.direction(dir);
}

void Player::setGameData(GameData gameData, const int num)
{
	m_gameData[gameData] += num;
}

void Player::reduceLife()
{
	m_gameData[Lives]--;
}

void Player::setFlickering()
{
	m_flickering = true;
	Clock::instance().getflickerPlayerClock().restart();
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