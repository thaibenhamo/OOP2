#pragma once
#include "Enemy.h"

Enemy::Enemy(sf::Vector2f location, Resources::Object object)
	: MovingObject(location, object)
{
	m_dir = Direction::Left;
}