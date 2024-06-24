#include "Player.h"
#include "StandingState.h"

namespace
{
	std::optional<Direction> toDirection(sf::Keyboard::Key key)
	{
		switch (key)
		{
		case sf::Keyboard::Left:
			return Direction::Left;

		default:
			return {};
		}
	}
} // end namespace

Player::Player(sf::Vector2f location, Resources::Object object)
	: MovingObject(location, object), m_state(std::make_unique<StandingState>())
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f, m_sprite.getGlobalBounds().height / 2.f);
    m_startPos = m_sprite.getPosition();
}

void Player::setPlayer(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

void Player::update(sf::Time delta)
{
	sf::Vector2f newLoc;

	setPrevLoc(m_sprite.getPosition());
	//if(Input::)

	//newLoc = findNewLoc(sf::Keyboard::Left, delta.asSeconds());
	//m_sprite.setPosition(newLoc);
	//m_sprite.move(toVector(m_dir) * delta.asSeconds() * 100.0f);
	m_animation.update(delta);
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
		// move player
	}

}

void Player::setStateAnimation(Direction dir)
{
	m_dir = dir;
	m_animation.direction(dir);
}