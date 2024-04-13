#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double x, double y)
    : BasicShape("Rectangle", x), m_height(y) {}

void Rectangle::print(int factor)
{
    double scaledLength;
    double scaledHeight;

    scaledLength = factor * m_sideLength;
    scaledHeight = factor * m_height;
    std::cout << m_name << "(w: " << scaledLength << ", h: " << scaledHeight << ")";
}
void Rectangle::draw(int factor)
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

void Rectangle::enlarge(int n)
{
    m_sideLength *= n;
    m_height *= n;
}

