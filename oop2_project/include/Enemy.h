#pragma once
#include "MovingObject.h"


class Enemy : public MovingObject {

public:
    using MovingObject::MovingObject;
    virtual ~Enemy() = default;

    Enemy(const Enemy&) = default;
    Enemy& operator=(const Enemy&) = default;
    Enemy(Enemy&&) = default;
    Enemy& operator=(Enemy&&) = default;

private:
    bool m_wasShot = false;

};