#pragma once
#include "CompositeShape.h"
#include <memory>

class Duplicate : public CompositeShape
{
public:
	Duplicate(const std::shared_ptr<Shape>shape1, const int n);
	virtual ~Duplicate() = default;
	virtual void print() const override;
	virtual void draw() override;
	virtual void enlarge(int n) override;
private:
	int m_n;
};