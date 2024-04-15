#pragma once
#include "BasicShape.h"

class Rectangle : public BasicShape
{
public:
	Rectangle(double x, double y);
	virtual ~Rectangle() = default;
private:
	virtual void draw(double factor) const override;
	virtual void print(double factor) const override;
	double m_height;
};