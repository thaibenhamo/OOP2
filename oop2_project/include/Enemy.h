#pragma once
#include "MovingObject.h"

class Enemy : public MovingObject 
{
public:
    Enemy(sf::Vector2f location, Resources::Object object);
    virtual ~Enemy() = default;

    void handleEnemyDeath();
    const bool getWasShot() const;
    void setWasShot(bool status);

protected:
    bool m_wasShot = false;
    sf::Clock m_clock;
};