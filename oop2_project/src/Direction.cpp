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
            return { 0, 0 };
    }
    throw std::runtime_error("Unknown direction");
}
