#pragma once
#include <string>

const char FILL = '*';
const char EMPTY = ' '; 

class Shape
{
public:
	Shape();
	virtual ~Shape() = default;
	virtual void print(int factor) = 0;
	virtual void draw(int factor) = 0;
	virtual void enlarge(int n) = 0;
private:
};