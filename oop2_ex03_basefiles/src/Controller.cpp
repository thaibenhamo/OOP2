#include "Controller.h"
#include <iostream>
#include <random> 
Controller::Controller() : m_timeLeft(60)
{
	std::random_device rd;
	//unsigned int seed = rd();
	srand(m_timeLeft);
	m_window.setFramerateLimit(60);
	m_window.create(sf::VideoMode(1200, 800), "Pick up sticks");
}
void Controller::startGame()
{
	while (m_window.isOpen()) 
	{
		sf::Time elapsed = m_clock.restart();
		m_timeLeft -= elapsed.asSeconds();

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
				handleClick(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
				break;
			default:
				break;
			}
		}
		m_board.update();
		m_toolBar.update(m_timeLeft, m_board.getSticksLeft(), m_board.getSticksRaised(), m_board.getPickableSticks());
		// display updated window
		m_window.clear(sf::Color::White);
		m_board.draw(m_window);
		m_toolBar.draw(m_window);
		m_window.display();
	}
}

void Controller::handleClick(const sf::Vector2f& mousePosition)
{
	m_board.handleMouseClick(mousePosition);
}
