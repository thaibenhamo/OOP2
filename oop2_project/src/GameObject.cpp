#pragma once
#include "GameObject.h"
#include "Animation.h"

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

GameObject::GameObject(sf::Vector2f location, Resources::Object object) 
	: m_animation(Resources::instance().animationData(object),
				  Direction::Stay, m_sprite)
{
	m_sprite.setPosition(location);
}

void GameObject::direction(sf::Keyboard::Key key)
{
	if (auto dir = toDirection(key))
	{
		m_dir = *dir;
		m_animation.direction(*dir);
	}
}

void GameObject::draw(sf::RenderTarget& window) const
{
	window.draw(m_sprite);
}

void GameObject::setCurrPos(sf::Vector2f loc) {

	m_sprite.setPosition(loc);
}

sf::Sprite GameObject::getSprite() const {

	return m_sprite;
}

