#pragma once
#include "Shape.h"
#include <string>

class BasicShape : public Shape
{
public:
	BasicShape(const std::string& name, double x);
	virtual ~BasicShape() = default;
	virtual void print() const;
	virtual void enlarge(int n) override;
protected:
	double m_sideLength;
};