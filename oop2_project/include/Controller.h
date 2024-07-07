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
	void handleEvents();
	void draw();
	void runGame();
	void runLevel();
	void printWinOrLoseBackground();
	void handleMove(const sf::Vector2f location);
	void handleClick(const sf::Vector2f location);

	Menu m_menu;
	Level m_level;									//for level
	InfoBar m_infoBar;								//for level information data
	sf::RenderWindow m_window;						//game render window
	sf::Time m_gameTime;							//for the time of the game 
	sf::Clock m_deltaTime;							//for delta time of game
	std::unique_ptr<Button> m_backButton;
	int m_levelNum = 1;
	bool m_inGame = true;
};
