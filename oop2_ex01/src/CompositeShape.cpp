#include "CompositeShape.h"
#include <string>
#include <iostream>

CompositeShape::CompositeShape(const std::shared_ptr<Shape>shape1)
	: Shape(), m_shape1(shape1), m_factor(1) {}

/*void CompositeShape::print(int factor)
{
	m_shape1->print(factor);
}*/

void CompositeShape::enlarge(int n)
{
	m_factor *= n;
	//m_shape1->enlarge(m_factor);
}





