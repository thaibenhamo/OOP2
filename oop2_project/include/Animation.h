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
    Direction m_dir = Direction::Stay;
    sf::Time m_elapsed = {};
    sf::Sprite& m_sprite;
    int m_index = 0;
};