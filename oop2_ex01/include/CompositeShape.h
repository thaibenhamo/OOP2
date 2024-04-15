#pragma once
#include "Shape.h"
#include <string>
#include <memory>

class CompositeShape : public Shape
{
public:
	CompositeShape(const std::shared_ptr<Shape>shape1);
	virtual ~CompositeShape() = default;
protected:
	std::shared_ptr<Shape> m_shape1;
};