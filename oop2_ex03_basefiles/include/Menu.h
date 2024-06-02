#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

class Menu
{
public:
	Menu();
	void draw(sf::RenderWindow& window);
	void loadMenuButtons();
	int handleMouseClick(const sf::Vector2f& mousePosition);
private:
	sf::RectangleShape m_startGameButton;
	sf::RectangleShape m_background;
	std::vector<Button> m_buttons;
	//bool m_startGame = false;
};