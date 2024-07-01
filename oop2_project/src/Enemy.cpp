#pragma once
#include "Enemy.h"

Enemy::Enemy(sf::Vector2f location, Resources::Object object)
	: MovingObject(location, object)
{
	m_dir = Direction::Left;
}

void Enemy::handleEnemyDeath() 
{
    /*  m_clock.restart();
      m_dir = State::Stay;
      m_animation.state(m_dir);
      m_wasShot = true;*/

      //just for now - before we handle death animation
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