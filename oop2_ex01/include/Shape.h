#pragma once
#include <string>

const char FILL = '*';
const char EMPTY = ' '; 

class Shape
{
public:
	Shape();
	virtual ~Shape() = default;
	virtual void print(double factor) const = 0;
	virtual void draw(double factor) = 0;
	virtual void enlarge(int n);
	virtual void reduce(int n);
	virtual double getFactor() const;
protected:
	double m_factor;
};