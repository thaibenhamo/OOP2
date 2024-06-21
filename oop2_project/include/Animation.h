#pragma once

#include "AnimationData.h"
#include "Resources.h"
#include "Direction.h"

class Animation
{
public:
    Animation(AnimationData& data, const Direction dir, sf::Sprite& sprite);
    virtual ~Animation() = default;

    void direction(const Direction dir);
    void update(const sf::Time delta);
    
private:
    void update();
    AnimationData& m_data;
    sf::Time m_elapsed = {};
    Direction m_dir = Direction::Stay;
    int m_index = 0;
    sf::Sprite& m_sprite;

};