#pragma once
#include "Resources.h"
#include "Level.h"
#include "InfoBar.h"
#include "Menu.h"


class Controller 
{
public:
	Controller();
	virtual ~Controller() = default;
	void run();

private:
	void handleEvents(/*sf::View& myView*/);
	void draw(/*sf::View myView*/);
	void runGame();
	void runLevel();
	void printWinOrLoseBackground();

	Menu m_menu;
	Level m_level;									//for level
	InfoBar m_infoBar;								//for level information data
	sf::RenderWindow m_window;						//game render window
	sf::Time m_gameTime;							//for the time of the game 
	sf::Clock m_deltaTime;							//for delta time of game
	int m_levelNum = 1;
};
