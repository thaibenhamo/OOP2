#include "BasicShape.h"
#include <string>
#include <iostream>

BasicShape::BasicShape(const std::string& name, double x)
	: Shape(),m_name(name), m_sideLength(x) {}

void BasicShape::print(int factor) 
{
	double size;
	size = factor * m_sideLength;
	std::cout << m_name << "(" << size << ")";
}

void BasicShape::enlarge(int n)
{
	m_sideLength *= n;
}