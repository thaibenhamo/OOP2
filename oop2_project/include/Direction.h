#pragma once
#include <SFML/Graphics.hpp>

enum class Direction
{
    Stay,
    Left,
    Right,
    Up,
    UpRight,
    UpLeft,
    Down,
    DownLeft,
    DownRight,
    Max
};

Direction opposite(Direction dir);
sf::Vector2f toVector(Direction dir);
