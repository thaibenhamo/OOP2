#include "CompositeShape.h"
#include <string>
#include <iostream>

CompositeShape::CompositeShape(const std::shared_ptr<Shape>shape1)
	: Shape(), m_shape1(shape1) {}

void CompositeShape::print(double factor) const
{
	std::cout << "(";
	m_shape1->print(m_shape1->getFactor() * factor);
	std::cout << ")";
}

void CompositeShape::draw(double factor) const
{
	m_shape1->draw(m_shape1->getFactor() * factor);
}