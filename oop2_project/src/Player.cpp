#include "Player.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "FallingState.h"

Player::Player(sf::Vector2f location, Resources::Object object)
	: MovingObject(location, object), m_state(std::make_unique<StandingState>()),
	m_animation(Resources::instance().animationData(object),
		Direction::Stay, m_sprite), m_gameData({START_LIVES, 0})
{
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
		m_sprite.getGlobalBounds().height / 2.f);
	m_startPos = m_sprite.getPosition();

	m_bubble.setTexture(Resources::instance().get(Resources::Bubble));

	m_bubble.setOrigin(m_bubble.getGlobalBounds().width / 2.f,
		m_bubble.getGlobalBounds().height / 2.f);

	// Set the initial position of the bubble to match the player's position
	m_bubble.setPosition(getPos());
	
}

void Player::setPlayer(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

void Player::update(sf::Time delta)
{
	if (m_flickering && 
		m_flickerClock.getElapsedTime().asSeconds() >= FLICKERING_DURATION)
	{
		m_flickering = false;
		m_sprite.setColor(sf::Color::White);
	}
	checkIfShotArrow();
	
	m_bubble.setPosition(getPos());
	movePlayer(delta);
	m_animation.update(delta);
	m_onWall = false;
}

void Player::checkIfShotArrow()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
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

void Player::draw(sf::RenderTarget& window)
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
	if(m_jumping || !m_onWall)
		handleInput(RELEASE_DOWN);

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

void Player::setStateAnimation(Direction dir)
{
	m_dir = dir;
	m_animation.direction(dir);
}

void Player::setGameDate(GameData gameData, int num)
{
	m_gameData[gameData] += num;
}

void Player::reduceLife()
{
	std::cout << m_gameData[Lives];
	m_gameData[Lives]--;
	m_flickering = true;
	m_flickerClock.restart();
	m_flickerStartTime = m_flickerClock.getElapsedTime();
}

const std::vector<int>& Player::getGameData() const
{
	return m_gameData;
}