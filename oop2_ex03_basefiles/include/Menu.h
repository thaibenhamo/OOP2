#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

class Menu
{
public:
	Menu();
	void draw(sf::RenderWindow& window);
	int handleMouseClick(const sf::Vector2f& mousePosition);

private:
	void loadMenuButtons();

	sf::RectangleShape m_startGameButton;
	sf::RectangleShape m_background;

	std::vector<Button> m_buttons;
};