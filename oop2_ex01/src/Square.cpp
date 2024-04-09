#include "Square.h"
#include <iostream>

Square::Square(double x) : BasicShape("Square", x) {}

void Square::draw() 
{
    for (int i = 0; i < m_sideLength; ++i) 
    {
        for (int j = 0; j < m_sideLength; ++j)
        {
            if (i == 0 || i == m_sideLength - 1 || j == 0 || j == m_sideLength - 1)
                std::cout << FILL << EMPTY;
            else 
                std::cout << EMPTY << EMPTY;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


