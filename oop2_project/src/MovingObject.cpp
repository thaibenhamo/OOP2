#pragma once
#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f location, Resources::Object object)
	: GameObject(location, object)/*, m_animation(Resources::instance().animationData(object),
		Direction::Stay, m_sprite)*/ 
{	
	m_prevLocation = getSprite().getPosition();
}

const sf::Vector2f MovingObject::getPrevLoc() const 
{
	return m_prevLocation;
}

const sf::Vector2f MovingObject::getPos() const
{
	return m_sprite.getPosition();
}

void MovingObject::setPos(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}

void MovingObject::setPrevLoc(const sf::Vector2f prevLoc) 
{
	m_prevLocation = prevLoc;
}
