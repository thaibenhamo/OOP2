#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Resources.h"
#include <iostream>
#include <cstdlib> // for std::system()
#include <fstream>


class Button
{
public:
	Button(sf::Vector2f size, int obj);
	virtual ~Button() = default;
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f pos);
	sf::FloatRect get_global_bounds()const;
	void setLooks(sf::Color color);
	void setTexture(sf::Texture &tex) { m_button.setTexture(&tex); }

protected:
	sf::RectangleShape m_button;
	sf::Texture m_texture;
};


