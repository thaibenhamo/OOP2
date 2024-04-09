#include "Triangle.h"
#include <iostream>
#include <string>

Triangle::Triangle(double x) : BasicShape("Triangle", x) {}

void Triangle::draw()
{
    for (int i = 1; i <= m_sideLength; ++i) 
    {
        // Print leading spaces
        std::cout << std::string(m_sideLength - i, ' ');

        // Print asterisks and spaces in the middle
        if (i == 1 || i == m_sideLength) 
        {
            for (int j = 1; j <= i; ++j) 
                std::cout << "* ";
        }
        else
        {
            std::cout << "*";
            std::cout << std::string(i * 2 - 3, ' ');
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
