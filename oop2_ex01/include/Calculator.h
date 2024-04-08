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
	void getOperationInput(std::string operation);
	void create();
	void draw();
	void duplicate();
	bool shapeIsValid(const int num);

private:
	void printList();
	std::vector<std::shared_ptr<Shape>> m_shapesList;
	std::unordered_map<std::string, Operation> m_functions;
};

