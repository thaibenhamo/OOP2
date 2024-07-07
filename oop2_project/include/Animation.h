#pragma once
#include "AnimationData.h"
#include "Resources.h"
#include "Direction.h"

class Animation
{
public:
    Animation(const AnimationData& data, const AnimationState state, sf::Sprite& sprite, const Direction dir);
    virtual ~Animation() = default;

    void state(const AnimationState state);
    void update(const sf::Time delta);
    void direction(const Direction dir);

private:
    void updateState();
    void updateDir();

    const AnimationData& m_data;
    AnimationState m_state;
    Direction m_dir;
    sf::Time m_elapsed = {};
    sf::Sprite& m_sprite;
    int m_index = 0;
};