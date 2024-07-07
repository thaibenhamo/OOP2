#include "Direction.h"
#include <stdexcept>

sf::Vector2f toVector(Direction dir)
{
    switch (dir)
    {
        case Direction::Stay:
            return { 0,0 };
        case Direction::Left:
            return { -1,0 };
        case Direction::Right:
            return { 1,0 };
        case Direction::Up:
            return { 0,-1 };
        case Direction::UpRight:
            return { 1,-1 };
        case Direction::UpLeft:
            return { -1,-1 };
        case Direction::Down:
            return { 0,1 };
        case Direction::DownRight:
            return { 1,1 };
        case Direction::DownLeft:
            return { -1,1 };

    }
    throw std::runtime_error("Unknown direction");
}

Direction opposite(Direction dir)
{
    switch (dir)
    {
    case Direction::Stay:
        return Direction::Right;
    case Direction::Left:
        return Direction::Right;
    case Direction::Right:
        return Direction::Left;
    case Direction::Up:
        return Direction::Down;
    case Direction::Down:
        return Direction::Up;
    case Direction::UpRight:
        return Direction::DownLeft;
    case Direction::UpLeft:
        return Direction::DownRight;
    case Direction::DownRight:
        return Direction::UpLeft;
    case Direction::DownLeft:
        return Direction::UpRight;
    }
    throw std::runtime_error("Unknown direction");
}