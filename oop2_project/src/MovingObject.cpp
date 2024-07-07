#pragma once
#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2f& location, const Resources::Object object)
	: GameObject(location/*, object*/)
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

void MovingObject::setPos(const sf::Vector2f& pos)
{
	m_sprite.setPosition(pos);
}

void MovingObject::setPrevLoc(const sf::Vector2f& prevLoc) 
{
	m_prevLocation = prevLoc;
}