#pragma once
#include "RandomEnemy.h"

static auto registerIt = Factory<MovingObject>::instance().registerType(
    ObjectType::RandomEnemyChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<MovingObject>
    {
        return std::make_unique<RandomEnemy>(position, object);
    }
);

RandomEnemy::RandomEnemy(const sf::Vector2f& location, const Resources::Object object)
    : Enemy(location, object), m_animation(Resources::instance().animationData(object),
                                           AnimationState::Move, m_sprite, Direction::Left)
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
                       m_sprite.getGlobalBounds().height * 0.404769f);
    
    m_randomEnemyClock.restart();
}

void RandomEnemy::update(sf::Time delta)
{
    if (m_changeDir || m_randomEnemyClock.getElapsedTime().asSeconds() >= 2)
    { 
        m_sprite.setPosition(m_prevLocation);
        m_dir = opposite(m_dir);
        m_animation.direction(m_dir);
        m_changeDir = false;
        m_randomEnemyClock.restart();
    }

    move(delta);
    m_animation.update(delta);
}

void RandomEnemy::move(sf::Time delta)
{
    m_prevLocation = m_sprite.getPosition();
    m_sprite.move(toVector(m_dir) * BASIC_ENEMY_SPEED * delta.asSeconds());
};