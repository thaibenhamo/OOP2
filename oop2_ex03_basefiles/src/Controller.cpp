#include <iostream>
#include <fstream>
#include "Controller.h"
#include "IncorrectFileException.h"
#include "InvalidGameStateException.h"


Controller::Controller() : m_timeLeft(10)
{
	srand((unsigned int)time(0));
	m_window.setFramerateLimit(60);
	m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pick up sticks");
}

void Controller::run()
{
	startMenu();
}

void Controller::startGame()
{
	m_clock.restart();

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
			{
				handleBoardClick(m_window.mapPixelToCoords({ event.mouseButton.x,
															 event.mouseButton.y }));
				break;
			}
			default:
				break;
			}
		}

		m_board.update();
		m_toolBar.update(m_timeLeft, m_board.getScore(), m_board.getSticksLeft(),
						 m_board.getSticksRaised(), m_board.getPickableSticks());

		if (m_timeLeft <= 0)
		{
			endScreen();
		}
			
		m_window.clear();
		m_board.draw(m_window);
		m_toolBar.draw(m_window);
		m_window.display();
	}
}

void Controller::startMenu()
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
			}

			case sf::Event::MouseButtonReleased:
			{
				handleMenuClick(m_window.mapPixelToCoords({ event.mouseButton.x,
															event.mouseButton.y }));
				break;
			}
			default:
				break;
			}
		}

		m_window.clear();
		m_menu.draw(m_window);
		m_window.display();
	}
}

void Controller::handleBoardClick(const sf::Vector2f& mousePosition)
{
	int option = m_board.handleMouseClick(mousePosition);

	switch (option)
	{
	case BoardOption::Hint:
	{
		m_board.showHint();
		break;
	}
	case BoardOption::Save:
	{
		m_board.saveBoard(m_timeLeft);
		break;
	}
	case BoardOption::Quit:
	{
		m_board = Board();
		m_clock.restart();
		startMenu();
		break;
	}

	default:
		break;
	}
}
void Controller::handleMenuClick(const sf::Vector2f& mousePosition)
{
	int option = m_menu.handleMouseClick(mousePosition);

	switch (option)
	{
	case MenuOption::startGame:
	{
		m_timeLeft = 10;
		startGame();
		break;
	}
	case MenuOption::Load:
	{
		try
		{
			m_board.load("Board.txt");
			m_timeLeft = m_board.getTimeLeftForLoad();
			startGame();
		}
		catch (const IncorrectFileException& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (const InvalidGameStateException& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	case MenuOption::Exit:
	{
		exit(EXIT_SUCCESS);
		break;
	}
	default:
		break;
	}
	
}

void Controller::endScreen()
{	
	sf::RectangleShape endScreen;
	endScreen.setSize(sf::Vector2f(WINDOW_WIDTH,WINDOW_HEIGHT));
	endScreen.setTexture(ResourcesManager::instance().getTexture("background"));

	sf::Text text;
	const sf::Font* font = ResourcesManager::instance().getFont();
	text.setFont(*font);
	text.setString("your score: " + std::to_string(m_board.getScore()));
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::Black);

	float xPos = (m_window.getSize().x - text.getLocalBounds().width) / 2.0f;
	text.setPosition(xPos, 290);

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
			}

			case sf::Event::MouseButtonPressed:
			{
				m_timeLeft = 90;
				m_clock.restart();
				m_board = Board();
				startMenu();
				return;
			}
			default:
				break;
			}
		}

		m_window.clear();
		m_window.draw(endScreen);
		m_window.draw(text);
		m_window.display();
	}
}
		
