#include "Animation.h"

Animation::Animation(AnimationData& data, const Direction dir, sf::Sprite& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite) {

    m_sprite.setTexture(Resources::instance().texture());
    update();
}

void Animation::direction(const Direction dir) {

    if (m_dir == dir)
        return;
    
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
    if (m_dir == Direction::Left || m_dir == Direction::DownLeft || m_dir == Direction::UpLeft)
        m_sprite.setScale(SCALE_TO_THE_LEFT);
    if (m_dir == Direction::Right || m_dir == Direction::DownRight || m_dir == Direction::UpRight)
        m_sprite.setScale(SCALE_TO_THE_RIGHT);

}
