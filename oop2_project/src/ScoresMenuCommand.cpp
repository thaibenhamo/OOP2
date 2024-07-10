#pragma once
#include "ScoresMenuCommand.h"

ScoresMenuCommand::ScoresMenuCommand()
{
    m_backButton->setPosition(sf::Vector2f(600, 734));
    m_backButton->setSize(sf::Vector2f(459, 93));

    for (int i = 0; i < 5; ++i)
    {
        m_scores.emplace_back(0, setText(i));
    }
}

bool ScoresMenuCommand::execute(sf::RenderWindow& window, int& score)
{
    bool inMenuCommand = true;
    updateValues(score);

    while (window.isOpen() && inMenuCommand)
    {
        show(window);

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                exit(EXIT_SUCCESS);
                break;
            case sf::Event::MouseMoved:
                handleMove(window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }));
                break;
            case sf::Event::MouseButtonReleased:
                auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                inMenuCommand = handleClick(location, score);
                break;
            }
        }
    }

    return m_inMenu;
}

void ScoresMenuCommand::show(sf::RenderWindow& window) const
{
    window.clear();

    auto sprite = sf::Sprite(Resources::instance().get(BackgroundType::ScoresMenuBackground));
    window.draw(sprite);

    m_backButton->draw(window);

    for (const auto& score : m_scores)
    {
        window.draw(score.second);
    }

    window.display();
}

void ScoresMenuCommand::handleMove(const sf::Vector2f& location)
{
    m_backButton->setLooks(sf::Color(255, 255, 255, 255)); // original

    if (m_backButton->getGlobalBounds().contains(location))
    {
        m_backButton->setLooks(sf::Color(255, 192, 203)); // darker
    }
}

bool ScoresMenuCommand::handleClick(const sf::Vector2f& location, int& numOfLevel)
{
    if (m_backButton->getGlobalBounds().contains(location))
    {
        return false;
    }
    return true;
}

void ScoresMenuCommand::updateValues(int numOfPoints)
{
    if (numOfPoints > m_scores.back().first)
    {
        m_scores.pop_back();

        int i = 0;
        for (auto it = m_scores.begin(); it != m_scores.end(); ++it, ++i)
        {
            if (numOfPoints > it->first)
            {
                m_scores.emplace(it, numOfPoints, setText(i));
                break;
            }
        }

        // Update positions for all scores
        for (size_t j = 0; j < m_scores.size(); ++j)
        {
            m_scores[j].second.setPosition(sf::Vector2f(830.f, float(270 + 50 * j)));
            m_scores[j].second.setString(std::to_string(m_scores[j].first));
        }
    }
    else
    {
        // Update text for existing scores if no new score is added
        for (size_t j = 0; j < m_scores.size(); ++j)
        {
            m_scores[j].second.setString(std::to_string(m_scores[j].first));
        }
    }
}

sf::Text ScoresMenuCommand::setText(int i)
{
    sf::Text text;
    text.setFont(Resources::instance().getFont());
    text.setCharacterSize(20);
    text.setFillColor(PINK);
    text.setOutlineThickness(0.5);
    text.setPosition(sf::Vector2f(830.f, float(270 + 50 * i)));

    return text;
}

