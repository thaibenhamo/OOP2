#include "BasicShape.h"
#include <string>
#include <iostream>

BasicShape::BasicShape(const std::string& name, double x)
	: Shape(name + "(" + std::to_string(int(x)) + ")"), m_x(x) {}

void BasicShape::print() const
{
	std::cout << m_name << std::endl;
}