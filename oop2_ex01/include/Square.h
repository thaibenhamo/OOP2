#pragma once
#include "BasicShape.h"

class Square : public BasicShape
{
public:
	Square(double x);
	virtual ~Square() = default;
	virtual void draw() override;

private:

};