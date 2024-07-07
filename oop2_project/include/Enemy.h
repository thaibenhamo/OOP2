#pragma once
#include "MovingObject.h"

class Enemy : public MovingObject 
{
public:
    Enemy(const sf::Vector2f& location, const Resources::Object object);
    virtual ~Enemy() = default;

    void handleEnemyDeath();
    void setWasShot(const bool status);
    const bool getWasShot() const;

protected:
    bool m_wasShot = false;
    bool m_makeCoin = false;
};