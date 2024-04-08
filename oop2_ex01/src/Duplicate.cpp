#include "Duplicate.h"
#include <memory>
#include <iostream>

Duplicate::Duplicate(const std::shared_ptr<Shape>shape1, const int n)
	: CompositeShape(std::to_string(n) + " * " + "(" + shape1->getName() + ")", shape1), m_n(n) {}

void Duplicate::print() const
{
	std::cout << m_name << std::endl;
}

void Duplicate::draw() 
{
	for (int i = 0; i < m_n; i++)
	{
		m_shape1->draw();
	}
	
}
