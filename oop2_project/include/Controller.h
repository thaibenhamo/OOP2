#pragma once
#include "Resources.h"
#include "Board.h"
#include "InfoBar.h"

class Controller {

public:
	Controller();
	virtual ~Controller() = default;

	void run();

private:
	void handleEvents(/*sf::View& myView*/);
	void draw(/*sf::View myView*/);
	void runGame();
	void runLevel();

	Board m_board;
	//Menu m_menu;									//for menu
	Infobar m_infobar;								//for level information data

	sf::RenderWindow m_window;						//game render window
	sf::Time m_gameTime;							//for the time of the game 
	sf::Clock m_deltaTime;							//for delta time of game


};
