#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double x) : BasicShape("Triangle", x) {}

void Triangle::draw()
{
    for (int i = 1; i <= m_x; i++) 
    {
        for (int j = 1; j <= (m_x - i); j++) 
            std::cout << " ";
        if (i == 1 || i == m_x) 
        { 
            for (int j = 1; j <= i; j++) 
                std::cout << "* ";
        }
        else 
        {
            std::cout << "*";
            for (int j = 1; j <= 2 * i - 3; j++)
                std::cout << " ";
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
