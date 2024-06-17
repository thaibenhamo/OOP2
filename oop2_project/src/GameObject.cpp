#pragma once
#include "GameObject.h"

GameObject::GameObject(sf::Vector2f location, Resources::Object object) 
{
	m_sprite.setTexture(Resources::instance().get(object));
	m_sprite.setPosition(location);
	
	m_sprite.setScale(2, 2);
	
}
//=========================================================
void GameObject::draw(sf::RenderTarget& target)
{
	target.draw(m_sprite);
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
