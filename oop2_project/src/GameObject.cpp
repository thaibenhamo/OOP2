#pragma once
#include "GameObject.h"


GameObject::GameObject(const sf::Vector2f& location/*, const Resources::Object object*/)
{
	m_sprite.setPosition(location);
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

sf::Sprite GameObject::getSprite() const 
{
	return m_sprite;
}

const bool GameObject::getIsDead() const
{
	return m_isDead;
}

void GameObject::setIsDead(const bool status)
{
	m_isDead = status;
}

