#pragma once
#include "Controller.h"
#include <SFML/OpenGL.hpp>

Controller::Controller()
	: m_window(sf::VideoMode(unsigned(SCREEN_X_SIZE), unsigned(SCREEN_Y_SIZE)/*, BPP*/),
							 "Twin shot", sf::Style::Default)
{
	m_window.setFramerateLimit(FPS);
}

void Controller::run() {

	srand(static_cast<unsigned>(time(nullptr)));

	//main loop
	while (m_window.isOpen()) {

		//m_menu.runMenu(m_window);
		m_board.setBoard(m_infobar.getLevelNum());
		runGame();
	}
}

//run level
void Controller::runGame() {

	while (!m_board.getWinGame()) 
	{
		runLevel();
	}
}

void Controller::runLevel() {

	auto delta = m_deltaTime.restart();
	//add init view
	while (true/*!m_board.getWinLevel()*/)
	{
		
		//updateView(myView);
		draw(/*myView*/);

		handleEvents(/*myView*/);
		delta = m_deltaTime.restart();
		m_board.updateObjects(delta);
		//handleInput();
	}

	//add restart view
}

void Controller::handleEvents(/*sf::View& myView*/) {
	for (auto event = sf::Event{}; m_window.pollEvent(event);) {
		switch (event.type) {
		case sf::Event::Closed:
			m_window.close();
			exit(EXIT_SUCCESS);
		case sf::Event::MouseMoved:
			break;
		case sf::Event::MouseButtonReleased:
			// auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			break;
		case sf::Event::KeyPressed:
			handleInput(event);
			break;
		case sf::Event::KeyReleased:
			handleInput(event); // Ensure KeyReleased is properly handled
			break;
		}
	}
}

void Controller::handleInput(sf::Event &event) 
{
	if (event.type == sf::Event::KeyPressed) {
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_board.playerDir(PRESS_UP);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			m_board.playerDir(PRESS_RIGHT);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			m_board.playerDir(PRESS_LEFT);
	
	}
	else if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right) 
			m_board.playerDir(RELEASE_WALK);
		if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right) 
			m_board.playerDir(RELEASE_JUMP);
		
	}
}

void Controller::draw(/*sf::View myView*/) {

	m_window.clear();
	m_window.draw(sf::Sprite(Resources::instance().get(BackgroundType::Background1)));
	m_board.drawObjects(m_window);

	//add draw InfoBar
	m_window.display();
}

