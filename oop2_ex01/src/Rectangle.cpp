#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double x, double y)
    : BasicShape("Rectangle", x), m_height(y) {}

void Rectangle::print(double factor) const
{
    std::cout << m_name << "(w: " << factor * m_sideLength << ", h: " << factor * m_height << ")";
}
void Rectangle::draw(double factor)
{
    for (int i = 0; i < (m_height * factor); ++i)
    {
        for (int j = 0; j < (m_sideLength * factor); ++j)
        {
            if (i == 0 || i == (m_height * factor) - 1 || 
                j == 0 || j == (m_sideLength * factor) - 1)
                std::cout << FILL << EMPTY;
            else
                std::cout << EMPTY << EMPTY;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
