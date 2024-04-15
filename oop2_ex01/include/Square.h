#pragma once
#include "BasicShape.h"

class Square : public BasicShape
{
public:
	Square(double x);
	virtual ~Square() = default;	
private:
	virtual void draw(double factor) const override;
};