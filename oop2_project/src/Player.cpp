#include "Player.h"

Player::Player(sf::Vector2f location, Resources::Object object) : MovingObject(location, object) {

    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f, m_sprite.getGlobalBounds().height / 2.f);
    m_startPos = m_sprite.getPosition();
}

const bool Player::getEnterExit() const
{
    return m_enterExit;
}