#include "BasicShape.h"
#include <string>
#include <iostream>

BasicShape::BasicShape(const std::string& name, double x)
	: Shape(name + "(" + std::to_string(int(x)) + ")"), m_sideLength(x) {}

void BasicShape::print() const
{
	std::cout << getName() << std::endl;
}

void BasicShape::enlarge(int n)
{
	m_sideLength *= n;

}