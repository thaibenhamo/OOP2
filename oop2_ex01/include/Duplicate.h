#pragma once
#include "CompositeShape.h"
#include <memory>

class Duplicate : public CompositeShape
{
public:
	Duplicate(const std::shared_ptr<Shape>shape1, const int n);
	virtual ~Duplicate() = default;
private:
	virtual void print(double factor) const override;
	virtual void draw(double factor) const override;
	int m_n;
};