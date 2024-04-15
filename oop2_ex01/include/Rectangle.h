#pragma once
#include "BasicShape.h"

class Rectangle : public BasicShape
{
public:
	Rectangle(double x, double y);
	virtual ~Rectangle() = default;
	virtual void draw(double factor) override;
	void print(double factor) const override;
private:
	void enlarge(int n);
	double m_height;
};