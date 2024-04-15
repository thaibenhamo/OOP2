#pragma once
#include "BasicShape.h"

class Triangle : public BasicShape
{
public:
	Triangle(double x);
	virtual ~Triangle() = default;
	virtual void draw(double factor) override;
private:
};