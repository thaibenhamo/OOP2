#include "Square.h"
#include <iostream>

Square::Square(double x) : BasicShape("Square", x) {}

void Square::draw(double factor) const
{
    auto roundSideLength = std::round(m_sideLength * factor);
    for (int i = 0; i < roundSideLength; ++i)
    {
        for (int j = 0; j < roundSideLength; ++j)
        {
            if (i == 0 || i == roundSideLength - 1 || j == 0 || j == roundSideLength - 1)
                std::cout << FILL << EMPTY;
            else 
                std::cout << EMPTY << EMPTY;
        }
        std::cout << std::endl;
    }
}


