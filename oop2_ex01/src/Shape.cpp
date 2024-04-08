#include "Shape.h"
#include <string>
#include <iostream>

Shape::Shape(const std::string& name) : m_name(name) {}

std::string Shape::getName() const
{
	return m_name;
}

