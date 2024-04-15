#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double x, double y)
    : BasicShape("Rectangle", x), m_height(y) {}

void Rectangle::print(double factor) const
{
    std::cout << m_name << "(w: " << factor * m_sideLength << ", h: " << factor * m_height << ")";
}
void Rectangle::draw(double factor) const
{
    auto roundHeight = std::round(m_height * factor);
    auto roundSideLength = std::round(m_sideLength * factor);

    for (int i = 0; i < roundHeight; ++i)
    {
        for (int j = 0; j < roundSideLength; ++j)
        {
            if (i == 0 || i == roundHeight - 1 || j == 0 || j == roundSideLength - 1)
                std::cout << FILL << EMPTY;
            else
                std::cout << EMPTY << EMPTY;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
