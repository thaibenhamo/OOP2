#pragma once
#include "Shape.h"
#include <vector>
#include <memory>
#include <unordered_map>

enum class Operation
{
	cre,
	en,
	red,
	draw,
	dup,
	stack,
	del,
	help,
	exit
};

class Calculator
{
public:
	Calculator();
	void run();
private:
	void performOperation(const std::string& operation);
	void create();
	void enlarge();
	void reduce();
	void draw();
	void duplicate();
	void deleteShape();
	void stack();
	void printList() const;
	void help() const;
	bool factorIsValid(const int factor);
	bool shapeIsValid(const int num);
	std::vector<std::shared_ptr<Shape>> m_shapesList;
	std::unordered_map<std::string, Operation> m_functions;
};

