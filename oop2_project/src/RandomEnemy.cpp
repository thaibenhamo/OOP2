#pragma once
#include "RandomEnemy.h"
#include <optional>

static auto registerIt = Factory<MovingObject>::instance().registerType(
    ObjectType::RandomEnemyChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<MovingObject>
    {
        return std::make_unique<RandomEnemy>(position, object);
    }
);

RandomEnemy::RandomEnemy(sf::Vector2f location, Resources::Object object)
    : Enemy(location, object), m_animation(Resources::instance().animationData(object),
                                           AnimationState::Move, m_sprite, Direction::Left)
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
                       m_sprite.getGlobalBounds().height / 2.f * 0.8f);
}

void RandomEnemy::update(sf::Time delta)
{
    if (m_changeDir)
    {
        changeDir();
        m_animation.direction(m_dir);
    }    
   
    move(delta);
    m_animation.update(delta);
}

void RandomEnemy::move(sf::Time delta)
{
    m_sprite.move(toVector(m_dir) * BASIC_ENEMY_SPEED * delta.asSeconds());
    m_changeDir = true;
};

void RandomEnemy::changeDir() 
{
    if (m_dir == Direction::Right) 
    {
        m_dir = Direction::Left;
    }
    else 
    {
        m_dir = Direction::Right;
    }
}
