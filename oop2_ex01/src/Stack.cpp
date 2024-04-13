#include "Stack.h"
#include <memory>
#include <iostream>

Stack::Stack(const std::shared_ptr<Shape>shape1, const std::shared_ptr<Shape>shape2)
	: CompositeShape(shape1), m_shape2(shape2) {}

void Stack::print(int factor)
{
	std::cout << "(";
	m_shape1->print(m_factor);
	std::cout << ") / (";
	m_shape2->print(m_factor);
	std::cout << ")";
}

void Stack::draw(int factor)
{
	m_shape1->draw(m_factor);
	m_shape2->draw(m_factor);
}

