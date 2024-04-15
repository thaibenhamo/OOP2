#pragma once
#include "CompositeShape.h"
#include <memory>

class Stack : public CompositeShape
{
public:
	Stack(const std::shared_ptr<Shape>shape1, const std::shared_ptr<Shape>shape2);
	virtual ~Stack() = default;	
private:
	virtual void print(double factor) const override;
	virtual void draw(double factor) const override;
	std::shared_ptr<Shape> m_shape2;
};