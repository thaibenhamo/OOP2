#include "Square.h"
#include <iostream>

Square::Square(double x) : BasicShape("Square", x) {}

void Square::draw(double factor) 
{
    for (int i = 0; i < (m_sideLength * factor); ++i) 
    {
        for (int j = 0; j < (m_sideLength * factor); ++j)
        {
            if (i == 0 || i == (m_sideLength * factor) - 1 || j == 0 || j == (m_sideLength * factor) - 1)
                std::cout << FILL << EMPTY;
            else 
                std::cout << EMPTY << EMPTY;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


