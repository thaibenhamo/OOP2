#include "Shape.h"
#include <string>
#include <iostream>

Shape::Shape() : m_factor(1) {}

double Shape::getFactor() const
{
	return m_factor;
}

void Shape::reduce(int n)
{
	m_factor *= 1.0 / n;
}

void Shape::enlarge(int n)
{
	m_factor *= n;
}

