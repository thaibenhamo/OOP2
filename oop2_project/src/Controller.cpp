#pragma once
#include "Controller.h"
#include <SFML/OpenGL.hpp>

Controller::Controller()
	: m_window(sf::VideoMode(unsigned(SCREEN_X_SIZE), unsigned(SCREEN_Y_SIZE)),
							 "Twin shot", sf::Style::Default)
{
	m_window.setFramerateLimit(FPS);
}

void Controller::run() 
{
	srand(static_cast<unsigned>(time(nullptr)));

	//main loop
	while (m_window.isOpen()) 
	{
		Resources::instance().playMusic(MusicType::MenuMusic);
		m_menu.activate(m_window, m_levelNum);
		runGame();
	}
}

//run levels
void Controller::runGame() 
{
	Resources::instance().playMusic(MusicType::GameMusic);
	//run the game until the player won or lost the game 
	while (m_levelNum <= NUM_OF_LEVELS && !m_level.getLoseLevel())
	{
		m_level.setLevel(m_levelNum);
		runLevel();
		m_levelNum++;
	}
	
	printWinOrLoseBackground();
	m_levelNum--;
	m_level.setLoseLevel(false);

}

//run level
void Controller::runLevel() 
{
	auto delta = m_deltaTime.restart();

	//run level until the player won or lost the level
	while (!m_level.getWinLevel() && !m_level.getLoseLevel())
	{
		handleEvents();
		delta = m_deltaTime.restart();

		m_level.handleInput(PRESS_BOTTON);
		m_level.updateObjects(delta);
		draw();
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
		//case sf::Event::MouseMoved:
		//	break;
		//case sf::Event::MouseButtonReleased:
		//	// auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
		//	break;
		}
	}
}

void Controller::draw() 
{
	m_window.clear();
	m_window.draw(sf::Sprite(Resources::instance().get(BackgroundType::Background1)));
	m_level.drawObjects(m_window);
	m_infoBar.draw(m_window, m_level.getInfoBarData());
	m_window.display();
}

void Controller::printWinOrLoseBackground()
{
	m_window.clear();
	if (m_levelNum > NUM_OF_LEVELS)
	{
		sf::Sprite winSprite(Resources::instance().get(BackgroundType::WinBackground));
		m_window.draw(winSprite);
		//Resources::instance().playSound(SoundType::WinGameSound);
	}

	if (m_level.getLoseLevel())
	{
		sf::Sprite winSprite(Resources::instance().get(BackgroundType::LoseBackground));
		m_window.draw(winSprite);
		//Resources::instance().playSound(SoundType::LoseGameSound);
	}
	
	m_window.display();
	
	while (true) //makes that the user need to press enter to continue
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			break;
		}
		// Add a short sleep to avoid consuming too much CPU
		sf::sleep(sf::milliseconds(100));
	}
}
