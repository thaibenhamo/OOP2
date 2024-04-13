#pragma once
#include "BasicShape.h"

class Rectangle : public BasicShape
{
public:
	Rectangle(double x);
	virtual ~Rectangle() = default;
	virtual void draw(int factor) override;
private:
};