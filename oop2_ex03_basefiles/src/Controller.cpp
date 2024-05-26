#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	//unsigned seed = static_cast<unsigned>(std::time(nullptr));
	//std::srand(seed);
	//std::cout << "Seed: " << seed << std::endl;
	m_window.setFramerateLimit(60);
	m_window.create(sf::VideoMode(1200, 800), "Pick up sticks");
}
void Controller::startGame()
{
	while (m_window.isOpen()) 
	{

		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				m_window.close();
				exit(EXIT_SUCCESS);
				break;
			}
			case sf::Event::MouseButtonReleased:
				handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
				break;
			default:
				break;
			}
		}


		// display updated window
		m_window.clear(sf::Color::White);
		m_board.draw(m_window);
		m_window.display();
	}
}

void Controller::handleClick(const sf::Vector2f& mousePosition)
{
	m_board.handleMouseClick(mousePosition);
}
