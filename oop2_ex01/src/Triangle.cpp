#include "Triangle.h"
#include <iostream>
#include <string>

Triangle::Triangle(double x) : BasicShape("Triangle", x) {}

void Triangle::draw(double factor) const
{
    auto roundSideLength = std::round(m_sideLength * factor);

    for (int i = 1; i <= roundSideLength; ++i)
    {
        // Print leading spaces
        std::cout << std::string(int(roundSideLength) - i, EMPTY);

        // Print asterisks and spaces in the middle
        if (i == 1 || i == roundSideLength)
        {
            for (int j = 1; j <= i; ++j) 
                std::cout << FILL << EMPTY;
        }
        else
        {
            std::cout << FILL;
            std::cout << std::string(i * 2 - 3, EMPTY);
            std::cout << FILL;
        }
        std::cout << std::endl;
    }
}

