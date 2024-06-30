#pragma once
#include "Coin.h"

static auto registerIt = Factory<StaticObject>::instance().registerType(
    ObjectType::CoinChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<StaticObject>
    {
        return std::make_unique<Coin>(position, object);
    }
);