#pragma once
#include "CompositeShape.h"
#include <memory>

class Duplicate : public CompositeShape
{
public:
	Duplicate(const std::shared_ptr<Shape>shape1, const int n);
	virtual ~Duplicate() = default;
	virtual void print(int factor) override;
	virtual void draw(int factor) override;
private:
	int m_n;
};