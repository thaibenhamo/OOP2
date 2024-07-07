#pragma once
#include "FlyingEnemy.h"

static auto registerIt = Factory<MovingObject>::instance().registerType(
    ObjectType::FlyingEnemyChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<MovingObject>
    {
        return std::make_unique<FlyingEnemy>(position, object);
    }
);

FlyingEnemy::FlyingEnemy(const sf::Vector2f& location, const Resources::Object object)
    : Enemy(location, object), m_animation(Resources::instance().animationData(object),
                               AnimationState::Move, m_sprite, Direction::Left)
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
                       m_sprite.getGlobalBounds().height / 2.f);
    m_flyingEnemyClock.restart();
}

void FlyingEnemy::update(sf::Time delta)
{
    m_animation.direction(m_dir);
    move(delta);
    m_animation.update(delta);

    //change direction if reaches current screens border
    if (isOutOfScreenBounds())
    {
        m_dir = opposite(m_dir);
        setPos(m_prevLocation);
    }
}

void FlyingEnemy::move(sf::Time delta)
{
    if (m_flyingEnemyClock.getElapsedTime().asSeconds() >= 2)
    {
        m_flyingEnemyClock.restart();

        if (distance(m_sprite.getPosition(), m_playerPosition) < CHASE_RADIUS) 
        {
            chasePlayer();
        }

        else 
        {
            changeDir();
        }
    }
    setPrevLoc(m_sprite.getPosition());
    m_sprite.move(toVector(m_dir) * BASIC_ENEMY_SPEED * delta.asSeconds());
}

void FlyingEnemy::changeDir()
{
    m_dir = static_cast<Direction>(rand() % static_cast<int>(Direction::Stay));
}

void FlyingEnemy::chasePlayer()
{
    sf::Vector2f direction = m_playerPosition - m_sprite.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length; // Normalize the direction vector
    // Determine the closest direction enum value
    if (std::abs(direction.x) > std::abs(direction.y)) 
    {
        m_dir = direction.x > 0 ? Direction::Right : Direction::Left;
    }
    else 
    {
        m_dir = direction.y > 0 ? Direction::Down : Direction::Up;
    }
}

float FlyingEnemy::distance(const sf::Vector2f& a, const sf::Vector2f& b) const
{
    sf::Vector2f diff = a - b;
    return std::sqrt(diff.x * diff.x + diff.y * diff.y);
}

bool FlyingEnemy::isOutOfScreenBounds() const
{
    return(m_sprite.getPosition().x - m_sprite.getGlobalBounds().width / 2 < 0 ||
           m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2 > SCREEN_X_SIZE ||
           m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2 > SCREEN_Y_SIZE ||
           m_sprite.getPosition().y - m_sprite.getGlobalBounds().height / 2 < 0);
}
