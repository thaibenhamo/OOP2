#include "Player.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "FallingState.h"

Player::Player(sf::Vector2f location, Resources::Object object)
	: MovingObject(location, object), m_state(std::make_unique<StandingState>()),
	m_animation(Resources::instance().animationData(object),
		Direction::Stay, m_sprite), m_gameData(CountGameData)
{
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
		m_sprite.getGlobalBounds().height / 2.f);
	m_startPos = m_sprite.getPosition();
	
}

void Player::setPlayer(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

void Player::update(sf::Time delta)
{
	if (m_flickering && 
		m_flickerClock.getElapsedTime().asSeconds() >= 0.05f)
	{
		m_flickering = false;
		m_sprite.setColor(sf::Color::White);
	}

	movePlayer(delta);
	m_animation.update(delta);
	m_onWall = false;
}

void Player::draw(sf::RenderTarget& window)
{
	if (m_flickering && 
		m_flickerClock.getElapsedTime().asSeconds() < 0.05f)
	{
		if (m_sprite.getColor() == sf::Color::Transparent)
			m_sprite.setColor(sf::Color::White);
		else
			m_sprite.setColor(sf::Color::Transparent);
	}

	window.draw(m_sprite);
}

void Player::movePlayer(sf::Time delta)
{
	//for the cases we are jumping or going down from a wall
	if(m_jumping || !m_onWall)
		handleInput(RELEASE_DOWN);

	m_sprite.move(toVector(m_dir) * delta.asSeconds() * SPEED);
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
	m_gameData[Lives]--;
	m_flickering = true;
	m_flickerClock.restart();
	m_flickerStartTime = m_flickerClock.getElapsedTime();
}

const std::vector<int>& Player::getGameData() const
{
	return m_gameData;
}