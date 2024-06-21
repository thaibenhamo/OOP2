#pragma once
#include "RandomEnemy.h"
#include <optional>

static auto registerIt = Factory<MovingObject>::instance().registerType(
    ObjectType::RandomEnemyChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<MovingObject>
    {
        return std::make_unique<RandomEnemy>(position, object);
    }
);

RandomEnemy::RandomEnemy(sf::Vector2f location, Resources::Object object) 
    : Enemy(location, object) {}