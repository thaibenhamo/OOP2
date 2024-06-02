#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button 
{
public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& label);

    void draw(sf::RenderWindow& window) const;
    bool isClicked(const sf::Vector2f& mousePos) const;

private:
    sf::RectangleShape m_shape;
    sf::Text m_text;
};