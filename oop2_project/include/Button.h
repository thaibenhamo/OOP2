#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

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
	void setSize(sf::Vector2f size);

protected:
	sf::RectangleShape m_button;
	sf::Texture m_texture;
};