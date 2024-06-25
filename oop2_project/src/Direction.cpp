#include "Direction.h"
#include <stdexcept>

Direction opposite(Direction dir)
{
    switch (dir)
    {
        case Direction::Stay:
            return Direction::Stay;
    }
       
    throw std::runtime_error("Unknown direction");
}

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
