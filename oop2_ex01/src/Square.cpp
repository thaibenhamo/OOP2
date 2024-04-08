#include "Square.h"
#include <iostream>

Square::Square(double x) : BasicShape("Square", x) {}

void Square::draw()
{
    for (int i = 0; i < m_x; ++i) 
    {
        if (i == 0 || i == m_x - 1) 
        {
            for (int j = 0; j < m_x; ++j) 
            {
                std::cout << FILL << EMPTY;
            }
        }
        else 
        {
            std::cout << FILL << EMPTY;
            for (int j = 0; j < m_x - 2; ++j) 
            {
                std::cout << EMPTY << EMPTY; 
            }
            std::cout << FILL << EMPTY;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    

    
}



