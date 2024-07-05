#include "Button.h"

Button::Button(sf::Vector2f size, ButtonType buttonType)
{
	m_button.setSize(size);
	m_button.setFillColor(sf::Color(255, 255, 255, 200));
	m_button.setTexture(&(Resources::instance().get(buttonType)));
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_button);
};

void Button::setPosition(sf::Vector2f pos)
{
	m_button.setPosition(pos);
}

sf::FloatRect Button::getGlobalBounds()const
{
	return m_button.getGlobalBounds();
};

void Button::setLooks(sf::Color color)
{
	m_button.setFillColor(color);
};