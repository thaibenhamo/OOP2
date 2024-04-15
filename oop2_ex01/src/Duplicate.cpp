#include "Duplicate.h"
#include <memory>
#include <iostream>

Duplicate::Duplicate(const std::shared_ptr<Shape>shape1, const int n)
	: CompositeShape(shape1), m_n(n) {}

void Duplicate::print(double factor) const
{
	std::cout << m_n << " * ";
	CompositeShape::print(factor);
}

void Duplicate::draw(double factor) const
{
	for (int i = 0; i < m_n; i++)
	{
		CompositeShape::draw(factor);
	}	
}

