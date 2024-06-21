#pragma once
#include <SFML/Graphics.hpp>

enum class Direction
{
    Stay,
    Max,
};

Direction opposite(Direction dir);
sf::Vector2f toVector(Direction dir);
