#include "Player.h"

namespace
{
	std::optional<Direction> toDirection(sf::Keyboard::Key key)
	{
		switch (key)
		{
		case sf::Keyboard::Space:
			return Direction::Stay;

		default:
			return {};
		}
	}
} // end namespace

Player::Player(sf::Vector2f location, Resources::Object object)
	: MovingObject(location, object) 
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f, m_sprite.getGlobalBounds().height / 2.f);
    m_startPos = m_sprite.getPosition();
}

void Player::setPlayer(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

void Player::updateAnimation(sf::Time delta)
{
	if (m_dir == Direction::Stay)
	{
		m_animation.update(delta);
	}
}
