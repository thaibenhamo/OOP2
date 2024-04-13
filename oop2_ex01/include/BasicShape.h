#pragma once
#include "Shape.h"
#include <string>

class BasicShape : public Shape
{
public:
	BasicShape(const std::string& name, double x);
	virtual ~BasicShape() = default;
	virtual void print(int factor);
	virtual void enlarge(int n) override;
protected:
	std::string m_name;
	double m_sideLength;
};