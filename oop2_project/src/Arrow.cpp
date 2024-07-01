#include "Arrow.h"

Arrow::~Arrow() {}

//static auto registerIt = Factory<MovingObject>::instance().registerType(
//    ObjectType::ArrowChar,
//    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<MovingObject> {
//        return std::make_unique<Arrow>(position, object);
//    }
//);

Arrow::Arrow(sf::Vector2f location, Resources::Object object, float dir)
    : MovingObject(location, object)
{
    m_sprite.setTexture(Resources::instance().get(object));

    // Set scaling according to arrow direction
    if (dir == 1)
    {
        m_sprite.setScale(SCALE_TO_THE_RIGHT);
        m_dir = Direction::Right;
    }
    else 
    {
        m_sprite.setScale(SCALE_TO_THE_LEFT);
        m_dir = Direction::Left;
    }

}


void Arrow::update(sf::Time delta)
{
    m_sprite.move(toVector(m_dir) * delta.asSeconds() * BULLET_SPEED);
}
