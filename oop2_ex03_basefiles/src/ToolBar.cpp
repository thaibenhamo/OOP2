#include "ToolBar.h"
#include "ResourcesManager.h"
#include <string>
#include <iostream> // for debug


ToolBar::ToolBar()
{
    const sf::Font* font = ResourcesManager::instance().getFont();

    m_timeText.setFont(*font);
    m_timeText.setCharacterSize(30);
    m_timeText.setFillColor(sf::Color::Black);
    m_timeText.setPosition(30, 20);

    m_score.setFont(*font);
    m_score.setCharacterSize(24);
    m_score.setFillColor(sf::Color::Black);
    m_score.setPosition(30, 90);

    m_sticksLeftText.setFont(*font);
    m_sticksLeftText.setCharacterSize(24);
    m_sticksLeftText.setFillColor(sf::Color::Black);
    m_sticksLeftText.setPosition(30, 130);

    m_sticksRaisedText.setFont(*font);
    m_sticksRaisedText.setCharacterSize(24);
    m_sticksRaisedText.setFillColor(sf::Color::Black);
    m_sticksRaisedText.setPosition(30, 170);

    m_pickableSticksText.setFont(*font);
    m_pickableSticksText.setCharacterSize(24);
    m_pickableSticksText.setFillColor(sf::Color::Black);
    m_pickableSticksText.setPosition(30, 210);
}

void ToolBar::update(float timeLeft, int score, int sticksLeft, int sticksRaised, int pickableSticks)
{
    int minutes = static_cast<int>(timeLeft) / 60;
    int seconds = static_cast<int>(timeLeft) % 60;

    m_timeText.setString("Time Left: " + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));
    m_score.setString("Score: " + std::to_string(score));
    m_sticksLeftText.setString("Sticks Left: " + std::to_string(sticksLeft));
    m_sticksRaisedText.setString("Sticks Raised: " + std::to_string(sticksRaised));
    m_pickableSticksText.setString("Pickable Sticks: " + std::to_string(pickableSticks));
}

void ToolBar::draw(sf::RenderWindow& window) const
{
    window.draw(m_timeText);
    window.draw(m_score);
    window.draw(m_sticksLeftText);
    window.draw(m_sticksRaisedText);
    window.draw(m_pickableSticksText);
}