#pragma once
#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& location, const Resources::Object object)
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

void Enemy::setWasShot(const bool status)
{
    m_wasShot = status;
}