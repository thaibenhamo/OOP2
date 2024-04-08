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
		std::cout << "Shape list is empty" << std::endl;
	}
	else 
	{
		std::cout << "List of the available shapes:" << std::endl;

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
	default:
		break;

	}
}

void Calculator::create()
{
	char shape;
	double x;
	//double y;

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
		return;
	case 'r':
		std::cout << "rectangle" << std::endl;
		break;
	default:
		std::cout << "invalid shape" << std::endl;
		return;
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
		std::cout << "invalid n" << std::endl;

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