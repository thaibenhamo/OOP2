#include "Stack.h"
#include <memory>
#include <iostream>

Stack::Stack(const std::shared_ptr<Shape>shape1, const std::shared_ptr<Shape>shape2)
	: CompositeShape(shape1), m_shape2(shape2) {}

void Stack::print(double factor) const
{
	CompositeShape::print(factor);
	std::cout << " / (";
	m_shape2->print(factor*m_shape2->getFactor());
	std::cout << ")";
}

void Stack::draw(double factor) const
{
	CompositeShape::draw(factor);
	m_shape2->draw(m_shape2->getFactor()*factor);
}

