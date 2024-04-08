#pragma once
#include <string>

const char FILL = '*';
const char EMPTY = ' '; 

class Shape
{
public:
	Shape(const std::string& name);
	virtual ~Shape() = default;
	virtual void print() const = 0;
	virtual void draw() = 0;
	virtual std::string getName() const;
private:
	std::string m_name;
};