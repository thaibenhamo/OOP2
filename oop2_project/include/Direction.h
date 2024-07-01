#pragma once
#include <SFML/Graphics.hpp>

enum class Direction
{
    Left,
    Right,
    Up,
    Down,
    Stay,
    UpRight,
    UpLeft, 
    DownLeft,
    DownRight,
    Max
};

sf::Vector2f toVector(Direction dir);
