#pragma once

#include <SFML/Graphics.hpp>

class ToolBar
{
public:
    ToolBar();
    void update(float timeLeft, int sticksLeft, int sticksRaised, int pickableSticks);
    void draw(sf::RenderWindow& window);

private:
    sf::Font m_font;
    sf::Text m_timeText;
    sf::Text m_sticksLeftText;
    sf::Text m_sticksRaisedText;
    sf::Text m_pickableSticksText;
};