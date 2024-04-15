#pragma once
#include "Shape.h"
#include <string>

class BasicShape : public Shape
{
public:
	BasicShape(const std::string& name, double x);
	virtual ~BasicShape() = default;
protected:
	virtual void print(double factor) const override;
	std::string m_name;
	double m_sideLength;
};