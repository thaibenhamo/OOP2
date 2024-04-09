#include "Calculator.h"
#include "Triangle.h"
#include "Square.h"
#include "Duplicate.h"
#include <string>
#include <iostream>

Calculator::Calculator() : m_shapesList() 
{
	m_functions["cre"] = Operation::cre;
	m_functions["en"] = Operation::en;
	m_functions["red"] = Operation::red;
	m_functions["draw"] = Operation::draw;
	m_functions["dup"] = Operation::dup;
	m_functions["stack"] = Operation::stack;
	m_functions["del"] = Operation::del;
	m_functions["help"] = Operation::help;
	m_functions["exit"] = Operation::exit;
}

void Calculator::run()
{
	std::string operation;

	printList();

	std::cin >> operation;

	while (true)
	{
		getOperationInput(operation);
		printList();
		std::cin >> operation;
	}
}

void Calculator::printList()
{
	if (m_shapesList.empty()) 
	{
		std::cout << "Shape list is empty\n\n";
	}
	else 
	{
		std::cout << "List of the available shapes:\n";

		for (int i = 0; i < m_shapesList.size(); i++)
		{
			std::cout << i << ".\t";
			m_shapesList[i]->print();
		}
	}

	std::cout << "Enter command('help' for the list of available commands): ";
}

void Calculator::getOperationInput(std::string operation)
{
	if (operation == "en" || operation == "red" || operation == "draw" || operation == "dup" ||
		operation == "stack" || operation == "del")
	{
		
	}
	switch (m_functions[operation])
	{
	case Operation::cre:
		create();
		break;
	case Operation::draw:
		draw();
		break;
	case Operation::dup:
		duplicate();
		break;
	case Operation::help:
		help();
		break;
	default:
		break;
	}
}

void Calculator::create()
{
	char shape;
	double x;
	double y;

	std::cin >> shape >> x;

	switch (shape)
	{
	case 't':
		if (x > 1)
			m_shapesList.push_back(std::make_shared<Triangle>(x));
		break;
	case 's':
		if (x > 1)
			m_shapesList.push_back(std::make_shared<Square>(x));
		break;
	case 'r':
		std::cout << "rectangle" << std::endl;
		break;
	default:
		std::cout << "invalid shape" << std::endl;
		break;
	}
}

void Calculator::draw()
{
	int num;
	std::cin >> num;
	
	if (shapeIsValid(num))
		m_shapesList[num]->draw();
}

void Calculator::duplicate()
{
	int num;
	int n;
	std::cin >> num >> n;

	if (shapeIsValid(num) && (n > 0))
		m_shapesList.push_back(std::make_shared<Duplicate>(m_shapesList[num], n));
	else
		std::cout << "invalid n\n";
}

bool Calculator::shapeIsValid(const int num)
{
	if (num < 0 || num > m_shapesList.size())
	{
		std::cout << "invalid shape number" << std::endl;
		return false;
	}
	return true;
}

void Calculator::help() const
{
	std::cout << "The available commands are:\n"
		"* cre(ate shape) < t - triangle | r - rectangle | s - square > x[y] -\n"
		"create new shape according to the chosen letter, with the given\n"
		"size(s) (y must be given only for a rectangle)\n"
		"* en(large) num n - enlarge the size of the sides of shape #num by n\n"
		"(1 - 10)\n"
		"* red(uce) num n - reduce the size of the sides of shape #num by n\n"
		"(1 - 10)\n"
		"* draw num - draw shape #num\n"
		"* dup(licate) num n - create a new shape which is a n times\n"
		"(vertical) duplication of shape #num\n"
		"* stack num1 num2 - create a new shape by stacking shape number #num1\n"
		"over shape number #num2\n"
		"* del(ete) num - delete shape #num from the shape list\n"
		"* help - print this command list\n"
		"* exit - exit the program\n\n";
}