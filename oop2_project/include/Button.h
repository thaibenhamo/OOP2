#pragma once
#include <SFML/Graphics.hpp>
//#include <vector>
#include "Resources.h"
//#include <iostream>
//#include <cstdlib> // for std::system()
//#include <fstream>

class Button
{
public:
	Button(const sf::Vector2f& size, const ButtonType buttonType);
	virtual ~Button() = default;

	void draw(sf::RenderWindow& window) const;
	void setPosition(const sf::Vector2f& pos);
	void setLooks(const sf::Color& color);
	void setTexture(sf::Texture& tex) { m_button.setTexture(&tex); }
	sf::FloatRect getGlobalBounds() const;

protected:
	sf::RectangleShape m_button;
	sf::Texture m_texture;
};