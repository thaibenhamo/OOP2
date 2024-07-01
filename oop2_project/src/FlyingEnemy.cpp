#pragma once
#include "FlyingEnemy.h"
#include <optional>

static auto registerIt = Factory<MovingObject>::instance().registerType(
    ObjectType::FlyingEnemyChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<MovingObject>
    {
        return std::make_unique<FlyingEnemy>(position, object);
    }
);

FlyingEnemy::FlyingEnemy(sf::Vector2f location, Resources::Object object)
    : Enemy(location, object)
{
    m_sprite.setTexture(Resources::instance().get(object));
}

void FlyingEnemy::update(sf::Time delta)
{
    move(delta);
    //m_animation.update(delta);
}

void FlyingEnemy::move(sf::Time delta)
{
    auto changeDirection = [this]
        {
            m_dir = static_cast<Direction>(rand() % static_cast<int>(Direction::Stay));
        };

    if (m_clock.getElapsedTime().asSeconds() >= 3)
    {
        m_clock.restart();
        changeDirection();
    }
    m_sprite.move(toVector(m_dir) * BASIC_ENEMY_SPEED * delta.asSeconds());

}
