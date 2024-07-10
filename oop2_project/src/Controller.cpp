#pragma once
#include "Controller.h"
#include <SFML/OpenGL.hpp>

Controller::Controller()
	: m_window(sf::VideoMode(unsigned(SCREEN_X_SIZE), unsigned(SCREEN_Y_SIZE)),
							 "Twin shot", sf::Style::Default)
{
	m_window.setFramerateLimit(FPS);
	m_backButton = std::make_unique<Button>(sf::Vector2f(347, 70), BackButton);
	m_backButton->setPosition(sf::Vector2f(80, 800));
}

void Controller::run() 
{
	srand(static_cast<unsigned>(time(nullptr)));

	//main loop
	while (m_window.isOpen()) 
	{
		Resources::instance().playMusic(MusicType::MenuMusic);
		m_menu.activate(m_window, m_levelNum, m_level.getScore());
		m_level.initScore();
		runGame();
	}
}

//run levels
void Controller::runGame() 
{
	Resources::instance().playMusic(MusicType::GameMusic);
	//run the game until the player won or lost the game 
	while (m_levelNum <= NUM_OF_LEVELS && !m_level.getLoseLevel() && m_inGame)
	{
		m_level.setLevel(m_levelNum);
		runLevel();
		m_levelNum++;
	}
	if (m_inGame)
	{
		printWinOrLoseBackground();
	}
	m_inGame = true;
	m_levelNum--;
	m_level.setLoseLevel(false);
	m_level.initLives();
}

//run level
void Controller::runLevel() 
{
	auto delta = m_deltaTime.restart();

	//run level until the player won or lost the level
	while (!m_level.getWinLevel() && !m_level.getLoseLevel() && m_inGame)
	{
		delta = m_deltaTime.restart();

		m_level.handleInput(PRESS_BOTTON);
		m_level.updateObjects(delta);
		draw();
		handleEvents();
	}	
}

void Controller::handleEvents() 
{
	for (auto event = sf::Event{}; m_window.pollEvent(event);) 
	{
		switch (event.type) 
		{
		case sf::Event::Closed:
			m_window.close();
			exit(EXIT_SUCCESS);
		case sf::Event::MouseMoved:
			handleMove(m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }));
			break;
		case sf::Event::MouseButtonReleased:
			auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
			handleClick(location);
			break;
		}
	}
}

void Controller::draw() 
{
	m_window.clear();
	m_window.draw(sf::Sprite(Resources::instance().get(BackgroundType::Background1)));
	m_level.drawObjects(m_window);
	m_infoBar.draw(m_window, m_level.getInfoBarData());
	m_backButton->draw(m_window);
	m_window.display();
}

void Controller::printWinOrLoseBackground()
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
			default:
				break;
			}
		}
		m_window.clear();

		if (m_levelNum > NUM_OF_LEVELS)
		{
			sf::Sprite winSprite(Resources::instance().get(BackgroundType::WinBackground));
			m_window.draw(winSprite);
		}

		if (m_level.getLoseLevel())
		{
			sf::Sprite winSprite(Resources::instance().get(BackgroundType::LoseBackground));
			m_window.draw(winSprite);
		}
		m_window.display();
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			break;
		}
	}
}

void Controller::handleMove(const sf::Vector2f location)
{
	m_backButton->setLooks(sf::Color(255, 255, 255, 255)); // original

	if (m_backButton->getGlobalBounds().contains(location))
	{
		m_backButton->setLooks(sf::Color(255, 192, 203)); // darker
	}
}

void Controller::handleClick(const sf::Vector2f location)
{
	if (m_backButton->getGlobalBounds().contains(location))
	{
		m_inGame = false;
	}
}
