#include "Calculator.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Duplicate.h"
#include "Stack.h"
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
		performOperation(operation);
		printList();
		std::cin >> operation;
	}
}

void Calculator::printList() const
{
	if(!m_shapesList.empty())
	{
		std::cout << "\nList of the available shapes:\n";

		for (int i = 0; i < m_shapesList.size(); i++)
		{
			std::cout << i << ".\t";
			m_shapesList[i]->print(m_shapesList[i]->getFactor());
			std::cout << "\n";
		}
	}
	else
		std::cout << "Shape list is empty\n\n";

	std::cout << "\nEnter command('help' for the list of available commands): ";
}

void Calculator::performOperation(const std::string& operation)
{
	int num, factor;

	if (!m_functions.contains(operation))
	{
		std::cout << "\nCommand not found\n";
		return;
	}

	switch (m_functions[operation])
	{
	case Operation::cre:
		create();
		break;
	case Operation::en:
		enlarge();
		break;
	case Operation::red:
		reduce();
		break;
	case Operation::draw:
		draw();
		break;
	case Operation::dup:
		duplicate();
		break;
	case Operation::stack:
		stack();
		break;
	case Operation::del:
		deleteShape();
		break;
	case Operation::help:
		help();
		break;
	case Operation::exit:
		std::cout << "Goodbye\n";
		exit(EXIT_SUCCESS);
	}
}

void Calculator::create()
{
	char shape;
	double sideLength;
	double height;

	std::cin >> shape >> sideLength;
	if (sideLength < 1)
		std::cout << "Invalid side length\n";

	switch (shape)
	{
	case 't':
			m_shapesList.push_back(std::make_shared<Triangle>(sideLength));
		break;
	case 's':
			m_shapesList.push_back(std::make_shared<Square>(sideLength));
		break;
	case 'r':
		std::cin >> height;
		if(height < 1)
			std::cout << "Invalid height\n";
		else
			m_shapesList.push_back(std::make_shared<Rectangle>(sideLength, height));
		break;
	default:
		std::cout << "Invalid shape type\n" << std::endl;
		break;
	}
}

void Calculator::enlarge()
{
	int num, factor;
	std::cin >> num >> factor;

	if (shapeIsValid(num) && factorIsValid(factor))
	{
		if (m_shapesList[num].use_count() > 1)
		{
			for (int i = num; i < m_shapesList.size(); ++i)
				m_shapesList[i]->enlarge(factor);
		}
		else
			m_shapesList[num]->enlarge(factor);
	}		
}

void Calculator::reduce()
{
	int num, factor ;
	std::cin >> num >> factor;

	if (shapeIsValid(num) && factorIsValid(factor))
	{
		if (m_shapesList[num].use_count() > 1)
		{
			for (int i = num; i < m_shapesList.size(); ++i)
				m_shapesList[i]->reduce(factor);
		}
		else
			m_shapesList[num]->reduce(factor);
	}
}

void Calculator::draw()
{
	int num;
	std::cin >> num;
	
	if (shapeIsValid(num))
		m_shapesList[num]->draw(1);
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

void Calculator::stack()
{
	int num1;
	int num2;

	std::cin >> num1 >> num2;

	if (shapeIsValid(num1) && shapeIsValid(num2))
		m_shapesList.push_back(std::make_shared<Stack>(m_shapesList[num1], (m_shapesList[num2])));
}

void Calculator::deleteShape()
{
	int num;
	std::cin >> num;
	if (shapeIsValid(num))
		m_shapesList.erase(m_shapesList.begin() + num);
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

bool Calculator::shapeIsValid(const int num)
{
	if (num < 0 || num > m_shapesList.size())
	{
		std::cout << "Invalid shape number" << std::endl;
		return false;
	}
	return true;
}

bool Calculator::factorIsValid(const int factor)
{
	if (factor < 2 || factor > 10)
	{
		std::cout << "Invalid scale factor" << std::endl;
		return false;
	}
	return true;
}