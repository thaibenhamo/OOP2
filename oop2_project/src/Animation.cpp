#include "Animation.h"

Animation::Animation(const AnimationData& data, const AnimationState state, sf::Sprite& sprite,
                     const Direction dir)
    : m_data(data), m_state(state), m_sprite(sprite), m_dir(dir)
{
    m_sprite.setTexture(Resources::instance().texture());
    updateState();
}

void Animation::state(const AnimationState state)
{
    if (m_state == state)
    {
        return;
    }
        
    m_state = state;
    m_index = 0;
    updateState();
}

void Animation::direction(const Direction dir) 
{
    if (m_dir == dir)
    {
        return;
    }
          
    m_dir = dir;
    m_index = 0;
    updateState();
}

void Animation::update(const sf::Time delta) 
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime) 
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_state)->second.size();
        updateState();
    }
}

void Animation::updateState()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_state)->second[m_index]);
    updateDir();
}

void Animation::updateDir()
{
    if (m_dir == Direction::Left ||
        m_dir == Direction::DownLeft ||
        m_dir == Direction::UpLeft)
    {
        m_sprite.setScale(SCALE_TO_THE_LEFT);
    }      

    if (m_dir == Direction::Right ||
        m_dir == Direction::DownRight ||
        m_dir == Direction::UpRight)
    {
        m_sprite.setScale(SCALE_TO_THE_RIGHT);
    }    
}