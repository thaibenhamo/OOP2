#pragma once
#include "LevelsMenuCommand.h"

LevelsMenuCommand::LevelsMenuCommand()
{
	for (int i = 0; i < NUM_OF_LEVELS; i++)
	{
		m_levelsButtons.push_back(std::make_unique<Button>(sf::Vector2f(115, 70), LevelLockButton));
		m_levelsButtons.back()->setPosition(sf::Vector2f(float(440 + 130 * i), 400.f));
	}

	m_levelsButtons[0]->setTexture(Resources::instance().get(Level1Button));
	m_unLock[0] = true;

	m_backButton->setPosition(sf::Vector2f(633, 550));

}

bool LevelsMenuCommand::execute(sf::RenderWindow& window, int& numOfLevel)
{
	bool inMenuCommand = true;
	updateValues(numOfLevel);//function that updtae the unlock array acoording to the numoflevel value

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
	return m_inMenu;
}

void LevelsMenuCommand::show(sf::RenderWindow& window) const
{
	window.clear();

	auto sprite = sf::Sprite(Resources::instance().get(BackgroundType::LevelsMenuBackground));
	window.draw(sprite);

	m_backButton->draw(window);
	for (auto& x : m_levelsButtons)
	{
		x->draw(window);
	}

	window.display();
}


void LevelsMenuCommand::handleMove(const sf::Vector2f& location)
{
	//for back button
	m_backButton->setLooks(sf::Color(255, 255, 255, 255)); // original

	if (m_backButton->getGlobalBounds().contains(location))
	{
		m_backButton->setLooks(sf::Color(255, 192, 203)); // darker
	}

	//for levels buttons
	for (auto& x : m_levelsButtons)
	{
		x->setLooks(sf::Color(255, 255, 255, 255)); // original
	}

	for (auto& x : m_levelsButtons)
	{
		if (x->getGlobalBounds().contains(location))
		{
			x->setLooks(sf::Color(255, 192, 203)); // darker
		}
	}
}

bool LevelsMenuCommand::handleClick(const sf::Vector2f& location, int& numOfLevel)
{
	if (m_backButton->getGlobalBounds().contains(location))
	{
		return false;
	}

	for (int level = 0; level < NUM_OF_LEVELS; level++)
	{
		if (m_levelsButtons[level]->getGlobalBounds().contains(location))
		{
			if (m_unLock[level])
			{
				numOfLevel = level + 1;
				m_inMenu = false;
				return false;

			}
		}
	}
	return true;
}

void LevelsMenuCommand::updateValues(int numOfLevel)
{
	m_inMenu = true;

	//unlock new levels if needed
	if (m_largestUnLockLevel < numOfLevel)
	{
		for (int i = 0; i < numOfLevel; i++)
		{
			if (m_unLock[i] == 0)
			{
				m_unLock[i] = 1;
				m_levelsButtons[i]->setTexture(Resources::instance().get(ButtonType(int(Level1Button) + i)));
			}
		}
		m_largestUnLockLevel = numOfLevel;
	}
}
