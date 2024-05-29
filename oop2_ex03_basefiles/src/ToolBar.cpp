#include "ToolBar.h"
#include <string>
#include <iostream> // for debug


ToolBar::ToolBar()
{
    if (!m_font.loadFromFile("FONT.ttf")) // Make sure you have the font file
    {
        std::cout << "font not found" << "\n";
    }

    m_timeText.setFont(m_font);
    m_timeText.setCharacterSize(24);
    m_timeText.setFillColor(sf::Color::Black);
    m_timeText.setPosition(10, 10);

    m_sticksLeftText.setFont(m_font);
    m_sticksLeftText.setCharacterSize(24);
    m_sticksLeftText.setFillColor(sf::Color::Black);
    m_sticksLeftText.setPosition(10, 40);

    m_sticksRaisedText.setFont(m_font);
    m_sticksRaisedText.setCharacterSize(24);
    m_sticksRaisedText.setFillColor(sf::Color::Black);
    m_sticksRaisedText.setPosition(10, 70);

    m_pickableSticksText.setFont(m_font);
    m_pickableSticksText.setCharacterSize(24);
    m_pickableSticksText.setFillColor(sf::Color::Black);
    m_pickableSticksText.setPosition(10, 100);
}

void ToolBar::update(float timeLeft, int sticksLeft, int sticksRaised, int pickableSticks)
{
    int minutes = static_cast<int>(timeLeft) / 60;
    int seconds = static_cast<int>(timeLeft) % 60;

    m_timeText.setString("Time Left: " + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));
    m_sticksLeftText.setString("Sticks Left: " + std::to_string(sticksLeft));
    m_sticksRaisedText.setString("Sticks Raised: " + std::to_string(sticksRaised));
    m_pickableSticksText.setString("Pickable Sticks: " + std::to_string(pickableSticks));
}

void ToolBar::draw(sf::RenderWindow& window)
{
    window.draw(m_timeText);
    window.draw(m_sticksLeftText);
    window.draw(m_sticksRaisedText);
    window.draw(m_pickableSticksText);
}