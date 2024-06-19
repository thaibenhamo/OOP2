#pragma once
#include "GameObject.h"

GameObject::GameObject(sf::Vector2f location, Resources::Object object) 
{
	m_sprite.setTexture(Resources::instance().get(object));
	m_sprite.setPosition(location);
}
//=========================================================
void GameObject::draw(sf::RenderTarget& window) const
{
	window.draw(m_sprite);
}
//=========================================================
void GameObject::setCurrPos(sf::Vector2f loc) {

	m_sprite.setPosition(loc);
}
//=========================================================
sf::Sprite GameObject::getSprite() const {

	return m_sprite;
}
//=========================================================
