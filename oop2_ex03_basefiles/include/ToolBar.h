#pragma once

#include <SFML/Graphics.hpp>

class ToolBar
{
public:
    ToolBar();
    void update(float timeLeft, int score, int sticksLeft, int sticksRaised, int pickableSticks);
    void draw(sf::RenderWindow& window) const;

private:
    sf::Text m_timeText;
    sf::Text m_score;
    sf::Text m_sticksLeftText;
    sf::Text m_sticksRaisedText;
    sf::Text m_pickableSticksText;
};