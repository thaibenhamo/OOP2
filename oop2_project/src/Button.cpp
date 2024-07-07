#include "Button.h"

Button::Button(const sf::Vector2f& size, const ButtonType buttonType)
{
	m_button.setSize(size);
	m_button.setFillColor(sf::Color(255, 255, 255, 200));
	m_button.setTexture(&(Resources::instance().get(buttonType)));
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_button);
};

void Button::setPosition(const sf::Vector2f& pos)
{
	m_button.setPosition(pos);
}

sf::FloatRect Button::getGlobalBounds() const
{
	return m_button.getGlobalBounds();
};

void Button::setLooks(const sf::Color& color)
{
	m_button.setFillColor(color);
};

void Button::setSize(sf::Vector2f size)
{
	m_button.setSize(size);
};