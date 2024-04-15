#include "CompositeShape.h"
#include <string>
#include <iostream>

CompositeShape::CompositeShape(const std::shared_ptr<Shape>shape1)
	: Shape(), m_shape1(shape1) {}






