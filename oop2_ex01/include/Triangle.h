#pragma once
#include "BasicShape.h"

class Triangle : public BasicShape
{
public:
	Triangle(double x);
	virtual ~Triangle() = default;
private:
	virtual void draw(double factor) const override;
};