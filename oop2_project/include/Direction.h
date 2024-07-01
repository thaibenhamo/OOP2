#pragma once
#include <SFML/Graphics.hpp>

enum class Direction
{
    Up,
    Left,
    Right,
    Down,
    Stay,
    UpRight,
    UpLeft, 
    DownLeft,
    DownRight,
    Max
};

Direction opposite(Direction dir);
sf::Vector2f toVector(Direction dir);
