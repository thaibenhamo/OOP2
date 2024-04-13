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
	void performOperation(std::string operation);
	void create();
	void enlarge();
	void draw();
	void duplicate();
	bool shapeIsValid(const int num);
	void deleteShape();
	void stack();

	void reduce();
private:
	void printList();
	void help() const;
	std::vector<std::shared_ptr<Shape>> m_shapesList;
	std::unordered_map<std::string, Operation> m_functions;
};

