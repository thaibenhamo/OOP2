#include "Duplicate.h"
#include <memory>
#include <iostream>

Duplicate::Duplicate(const std::shared_ptr<Shape>shape1, const int n)
	: CompositeShape(shape1), m_n(n) {}

void Duplicate::print(double factor) const
{
	std::cout << m_n << " * (";
	m_shape1->print(m_shape1->getFactor()*factor);
	std::cout << ")";
}

void Duplicate::draw(double factor) 
{
	for (int i = 0; i < m_n; i++)
	{
		m_shape1->draw(m_shape1->getFactor()*factor);
	}	
}

