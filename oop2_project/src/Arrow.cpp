#include "Arrow.h"

Arrow::~Arrow() {}

static auto registerIt = Factory<MovingObject>::instance().registerType(
    ObjectType::ArrowChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<MovingObject> 
    {
        return std::make_unique<Arrow>(position, object);
    }
);

Arrow::Arrow(sf::Vector2f location, Resources::Object object)
    : MovingObject(location, object)
{
    m_sprite.setTexture(Resources::instance().get(object));
}

void Arrow::update(sf::Time delta)
{
    m_sprite.move(toVector(m_dir) * delta.asSeconds() * ARROW_SPEED);
}

void Arrow::setDir(const Direction dir)
{
    m_dir = dir;
    if (dir == Direction::Stay)
    {
        return;
    }
        
    // Set scaling according to arrow direction
    if (dir == Direction::Right)
    {
        m_sprite.setScale(SCALE_TO_THE_RIGHT);
        m_sprite.setPosition(m_sprite.getPosition().x + OFFSET_X_FOR_ARROW,
                             m_sprite.getPosition().y + OFFSET_Y_FOR_ARROW);
    }
    else
    {
        m_sprite.setScale(SCALE_TO_THE_LEFT);
        m_sprite.setPosition(m_sprite.getPosition().x - OFFSET_X_FOR_ARROW,
                             m_sprite.getPosition().y + OFFSET_Y_FOR_ARROW);
    }
    m_prevLocation = getSprite().getPosition();
}