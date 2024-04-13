#pragma once
#include "CompositeShape.h"
#include <memory>

class Stack : public CompositeShape
{
public:
	Stack(const std::shared_ptr<Shape>shape1, const std::shared_ptr<Shape>shape2);
	virtual ~Stack() = default;
	virtual void print(int factor) override;
	virtual void draw(int factor) override;
private:
	std::shared_ptr<Shape> m_shape2;
};