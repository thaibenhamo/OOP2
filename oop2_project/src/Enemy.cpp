#pragma once
#include "Enemy.h"

Enemy::Enemy(sf::Vector2f location, Resources::Object object)
	: MovingObject(location, object)
{
	m_dir = Direction::Left;
}

void Enemy::handleEnemyDeath() 
{
    m_isDead = true;
}

const bool Enemy::getWasShot() const
{
    return m_wasShot;
}

void Enemy::setWasShot(bool status)
{
    m_wasShot = status;
}