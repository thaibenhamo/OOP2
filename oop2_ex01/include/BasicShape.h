#pragma once
#include "Shape.h"
#include <string>

class BasicShape : public Shape
{
public:
	BasicShape(const std::string& name, double x);
	virtual ~BasicShape() = default;
	virtual void print() const;
protected:
	double m_x;
};