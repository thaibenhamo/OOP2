#include "Animation.h"

Animation::Animation(AnimationData& data, const Direction dir, sf::Sprite& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite) {

    m_sprite.setTexture(Resources::instance().texture());
    update();
}

void Animation::direction(const Direction dir) {

    if (m_dir == dir || dir == Direction::Stay) 
    {

        return;
    }

    m_dir = dir;
    m_index = 0;
    update();
}

void Animation::update(const sf::Time delta) {

    m_elapsed += delta;
    if (m_elapsed >= AnimationTime) {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_dir)->second.size();
        update();
    }
}

void Animation::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
}
