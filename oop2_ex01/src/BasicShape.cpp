#include "BasicShape.h"
#include <string>
#include <iostream>

BasicShape::BasicShape(const std::string& name, double x)
	: Shape(),m_name(name), m_sideLength(x) {}

void BasicShape::print(double factor) const 
{
	std::cout << m_name << "(" << factor * m_sideLength << ")";
}
