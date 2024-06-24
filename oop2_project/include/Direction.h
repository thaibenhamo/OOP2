#pragma once
#include <SFML/Graphics.hpp>

enum class Direction
{
    Stay,
    Left,
    Max,
};

Direction opposite(Direction dir);
sf::Vector2f toVector(Direction dir);
