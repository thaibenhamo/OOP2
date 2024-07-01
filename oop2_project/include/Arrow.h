#pragma once
#include "MovingObject.h"

class Arrow : public MovingObject 
{
public:
    Arrow(sf::Vector2f location, Resources::Object object, float scale);
    ~Arrow();

    void update(sf::Time delta) override;

private:
};