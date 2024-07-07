#pragma once
#include "Resources.h"
#include "MenuCommand.h"
#include "Button.h"


typedef std::pair<Button, std::unique_ptr<MenuCommand>> option;

class Menu {

public:
	Menu();
	~Menu() {}

	void activate(sf::RenderWindow& window, int& numOfLevel, int score);

private:
	std::vector<option> m_options;
	sf::Sprite m_CloudsSprite;

	void show(sf::RenderWindow& window);
	void handleMove(const sf::Vector2f& location);
	bool handleClick(const sf::Vector2f& location, sf::RenderWindow& window, int& numOfLevel, int score);

};