#pragma once
#include "HelpMenuCommand.h"

HelpMenuCommand::HelpMenuCommand()
{
	m_backButton->setPosition(sf::Vector2f(1120, 770));
}

bool HelpMenuCommand::execute(sf::RenderWindow& window, int& numOfLevel)
{
	bool inMenuCommand = true;

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
				inMenuCommand = handleClick(location, numOfLevel);
				break;
			}
		}
	}
	return 	m_inMenu;
}

void HelpMenuCommand::show(sf::RenderWindow& window) const
{
	window.clear();

	auto sprite = sf::Sprite(Resources::instance().get(BackgroundType::HelpMenuBackground));
	window.draw(sprite);

	m_backButton->draw(window); // original

	window.display();
}

void HelpMenuCommand::handleMove(const sf::Vector2f& location)
{
	m_backButton->setLooks(sf::Color(255, 255, 255, 255)); // original

	if (m_backButton->getGlobalBounds().contains(location))
	{
		m_backButton->setLooks(sf::Color(255, 192, 203)); // darker
	}
}

bool HelpMenuCommand::handleClick(const sf::Vector2f& location, int& numOfLevel)
{
	if (m_backButton->getGlobalBounds().contains(location))
	{
		return false;
	}
	return true;
}