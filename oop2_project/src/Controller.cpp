#pragma once
#include "Controller.h"
#include <SFML/OpenGL.hpp>

Controller::Controller()
	: m_window(sf::VideoMode(unsigned(SCREEN_X_SIZE), unsigned(SCREEN_Y_SIZE)/*, BPP*/),
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
		//m_menu.runMenu(m_window);
		m_level.setLevel(m_levelNum);
		runGame();
	}
}

//run level
void Controller::runGame() 
{
	while (!m_level.getWinGame()) 
	{
		runLevel();
	}
}

void Controller::runLevel() 
{
	auto delta = m_deltaTime.restart();
	//add init view
	while (true/*!m_board.getWinLevel()*/)
	{
		//updateView(myView);
		handleEvents(/*myView*/);
		delta = m_deltaTime.restart();

		m_level.handleInput(PRESS_BOTTON);
		m_level.updateObjects(delta);
		
		draw(/*myView*/);
	}
	//add restart view
}

void Controller::handleEvents(/*sf::View& myView*/) 
{
	for (auto event = sf::Event{}; m_window.pollEvent(event);) 
	{
		switch (event.type) 
		{
		case sf::Event::Closed:
			m_window.close();
			exit(EXIT_SUCCESS);
		case sf::Event::MouseMoved:
			break;
		case sf::Event::MouseButtonReleased:
			// auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			break;
		}
	}
}

void Controller::draw(/*sf::View myView*/) 
{
	m_window.clear();
	m_window.draw(sf::Sprite(Resources::instance().get(BackgroundType::Background1)));
	m_level.drawObjects(m_window);
	m_infoBar.draw(m_window, m_level.getInfoBarData());
	m_window.display();
}
