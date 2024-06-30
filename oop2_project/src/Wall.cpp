#pragma once
#include "Wall.h"

static auto registerIt = Factory<StaticObject>::instance().registerType(
    ObjectType::WallChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<StaticObject>
    {
        return std::make_unique<Wall>(position, object);
    }
);
