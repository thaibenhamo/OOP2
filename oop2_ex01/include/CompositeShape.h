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
	virtual void print(double factor) const override;
	virtual void draw(double factor) const override;
	std::shared_ptr<Shape> m_shape1;
};