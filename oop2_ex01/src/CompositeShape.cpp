#include "CompositeShape.h"
#include <string>
#include <iostream>

CompositeShape::CompositeShape(const std::string& name, const std::shared_ptr<Shape>shape1)
	: Shape(name), m_shape1(shape1) {}



