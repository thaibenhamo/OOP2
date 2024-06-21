#pragma once
#include "MovingObject.h"


class Enemy : public MovingObject {

public:
    using MovingObject::MovingObject;
    virtual ~Enemy() = default;

private:
    bool m_wasShot = false;

};