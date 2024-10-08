#include <iostream>
#include "Button.h"
#include "ResourcesManager.h"

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& label) 
{
    const sf::Font* font = ResourcesManager::instance().getFont();
    m_shape.setSize(size);
    m_shape.setPosition(position);
    m_shape.setTexture(ResourcesManager::instance().getTexture("button"));
    m_text.setFont(*font);
    m_text.setString(label);
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color(61,45,48));
    m_text.setPosition(position.x + (size.x - m_text.getLocalBounds().width) / 2,
                       position.y + (m_text.getLocalBounds().height) / 2 
    );
}

void Button::draw(sf::RenderWindow& window) const
{
    window.draw(m_shape);
    window.draw(m_text);
}

bool Button::isClicked(const sf::Vector2f& mousePos) const 
{
    return m_shape.getGlobalBounds().contains(mousePos);
}