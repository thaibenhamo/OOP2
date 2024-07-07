#include "Menu.h"
#include "Button.h"
#include "LevelsMenuCommand.h"
#include "HelpMenuCommand.h"
#include "ScoresMenuCommand.h"
#include "Button.h"
#include "MenuCommand.h"

Menu::Menu()
{
	m_options.emplace_back(std::make_pair(Button(sf::Vector2f(210, 70), PlayButton), 
						   std::make_unique<LevelsMenuCommand>()));
	m_options.emplace_back(std::make_pair(Button(sf::Vector2f(210, 70), HelpButton), 
						   std::make_unique<HelpMenuCommand>()));
	m_options.emplace_back(std::make_pair(Button(sf::Vector2f(210, 70), ScoresButton), 
					       std::make_unique<ScoresMenuCommand>()));

	m_options[0].first.setPosition({ 730.f, float(550 + 80 * 0) });
	m_options[1].first.setPosition({ 730.f, float(550 + 80 * 1) });
	m_options[2].first.setPosition({ 730.f, float(550 + 80 * 2) });

	m_CloudsSprite.setTexture(Resources::instance().get(BackgroundType::CloudsBackground));
	m_CloudsSprite.setPosition(0.f, 150.f);
	m_CloudsSprite.setColor(sf::Color(255, 255, 255, 200));
}

void Menu::activate(sf::RenderWindow& window, int& numOfLevel, int score)
{
	bool inMenu = true;

	while (window.isOpen() && inMenu) 
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
				inMenu = handleClick(location, window, numOfLevel, score);
				break;
			}
		}
	}
}

void Menu::show(sf::RenderWindow& window)
{
	window.clear();

	auto sprite = sf::Sprite(Resources::instance().get(BackgroundType::Background1));
	window.draw(sprite);
	window.draw(m_CloudsSprite);

	auto sprite2 = sf::Sprite(Resources::instance().get(BackgroundType::MenuBackground));
	sprite2.setPosition({ 325.f, 90.f });
	window.draw(sprite2);

	for (auto& x : m_options)
	{
		x.first.draw(window);
	}

	window.display();

}


void Menu::handleMove(const sf::Vector2f& location)
{
	for (auto& x : m_options)
	{
		x.first.setLooks(sf::Color(255, 255, 255, 255)); // original
	}

	for (auto& x : m_options)
	{
		if (x.first.getGlobalBounds().contains(location))
		{
			x.first.setLooks(sf::Color(255, 192, 203)); // darker
		}
	}
}


bool Menu::handleClick(const sf::Vector2f& location, sf::RenderWindow& window, int& numOfLevel, int score)
{
	for (int i = 0; i < 3; i++)
	{
		if (m_options[i].first.getGlobalBounds().contains(location))
		{
			if (i == 2)
			{
				return m_options[i].second->execute(window, score); // darker
			}
			return m_options[i].second->execute(window, numOfLevel); // darker
		}
	}
	return true;
}