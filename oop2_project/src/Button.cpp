#include "Button.h"

Button::Button(sf::Vector2f size, int obj)
{
	m_button.setSize(size);
	m_button.setFillColor(sf::Color(255, 255, 255, 200));
	m_texture = Resources::instance().get((ButtonType)((int)(ButtonType::PlayButton)+obj));
	m_button.setTexture(&m_texture);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_button);
};

void Button::setPosition(sf::Vector2f pos)
{
	m_button.setPosition(pos);
}

sf::FloatRect Button::get_global_bounds()const
{
	return m_button.getGlobalBounds();
};

void Button::setLooks(sf::Color color)
{
	m_button.setFillColor(color);
};