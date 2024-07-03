#pragma once
#include "Wall.h"

static auto registerIt = Factory<StaticObject>::instance().registerType(
    ObjectType::WallChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<StaticObject>
    {
        return std::make_unique<Wall>(position, object);
    } 
);

Wall::Wall(sf::Vector2f location, Resources::Object object) 
    : StaticObject(location, object)
{
    m_sprite.setOrigin(0.f, m_sprite.getGlobalBounds().height / 2.f);
}