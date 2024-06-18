#pragma once
#include "Controller.h"
#include <SFML/OpenGL.hpp>

Controller::Controller()
	: m_window(sf::VideoMode(unsigned(SCREEN_X_SIZE), unsigned(SCREEN_Y_SIZE)/*, BPP*/),
							 "Twin shot", sf::Style::Default)
{
	m_window.setFramerateLimit(FPS);
}
//=========================================================
void Controller::run() {

	srand(static_cast<unsigned>(time(nullptr)));

	//main loop
	while (m_window.isOpen()) {

		//m_menu.runMenu(m_window);
		m_board.setBoard(m_infobar.getLevelNum());
		runGame();
	}
}

//=========================================================
//run level
void Controller::runGame() {

	//Resources::instance().playMusic(MusicType::GameMusic);

	while (!m_board.getWinGame()) 
	{
		runLevel();
		m_board.setBoard(m_infobar.getLevelNum());
	}

	//m_infobar.setLevelNum(FIRST_LEVEL);
	//m_board.setWinGame(false);
}

//=========================================================
void Controller::runLevel() {

	//add init view
	while (true/*!m_board.getWinLevel()*/)
	{
		
		//updateView(myView);
		draw(/*myView*/);

		handleEvents(/*myView*/);
		//delta = m_deltaTime.restart();
		//m_board.moveObjects(delta);
	}

	//add restart view
}

//=========================================================
void Controller::handleEvents(/*sf::View& myView*/) {

	for (auto event = sf::Event{}; m_window.pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			exit(EXIT_SUCCESS);
		/*case sf::Event::Resized:
			myView.setSize(SCREEN_X_SIZE * (m_window.getSize().x) / float(m_window.getSize().y), SCREEN_Y_SIZE);
			break;*/
		case sf::Event::MouseMoved:
			break;
		case sf::Event::MouseButtonReleased:
			auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			//m_infoBar.handleSoundStatus(location);
			break;
		}
		//updatePlayerDir();
	}
}

//=========================================================
void Controller::draw(/*sf::View myView*/) {

	m_window.clear();
	m_window.draw(sf::Sprite(Resources::instance().get(BackgroundType::Background1)));
	m_board.drawObjects(m_window);

	//add draw InfoBar

	m_window.display();
}

