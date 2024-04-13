#pragma once
#include "BasicShape.h"

class Rectangle : public BasicShape
{
public:
	Rectangle(double x, double y);
	virtual ~Rectangle() = default;
	virtual void draw(int factor) override;
	void print(int factor) override;
	void enlarge(int n);
private:
	double m_height;
};