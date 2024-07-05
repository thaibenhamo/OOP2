#include "Menu.h"
#include "Button.h"
#include "LevelsMenuCommand.h"
#include "HelpMenuCommand.h"
#include "Button.h"
#include "MenuCommand.h"


Menu::Menu()
{
	m_options.emplace_back(std::make_pair(Button(sf::Vector2f(210, 70), PlayButton), std::make_unique<LevelsMenuCommand>()));
	m_options.emplace_back(std::make_pair(Button(sf::Vector2f(210, 70), HelpButton), std::make_unique<HelpMenuCommand>()));
	m_options[0].first.setPosition({ 730.f, float(550 + 80 * 0) });
	m_options[1].first.setPosition({ 730.f, float(550 + 80 * 1) });

	m_CloudsSprite.setTexture(Resources::instance().get(BackgroundType::CloudsBackground));
	m_CloudsSprite.setPosition(0.f, 150.f);
	m_CloudsSprite.setColor(sf::Color(255, 255, 255, 200));
}

void Menu::activate(sf::RenderWindow& window, int& numOfLevel)
{
	bool inMenu = true;

	while (window.isOpen() && inMenu) {
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
				handleMove(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
				break;
			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				inMenu = handleClick(location, window, numOfLevel);//if click - do on options execute() 
				break;
			}
		}
	}

	/*	loop that checks mouse move, click, exit
			if move - do on the button setLooks
			if click - do on options execute()
	*/

}

void Menu::show(sf::RenderWindow& window)
{
	window.clear();

	//לעשות את זה בבנאי עם עננים ורץ על לולאה
	auto sprite = sf::Sprite(Resources::instance().get(BackgroundType::Background1));
	window.draw(sprite);
	window.draw(m_CloudsSprite);

	auto sprite2 = sf::Sprite(Resources::instance().get(BackgroundType::MenuBackground));
	sprite2.setPosition({ 325.f, 90.f });
	window.draw(sprite2);

	for (auto& x : m_options)
	{
		x.first.draw(window); // original
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
			x.first.setLooks(sf::Color(255, 192, 203)/*(255, 255, 255, 220)*/); // darker
		}
	}
}


bool Menu::handleClick(const sf::Vector2f& location, sf::RenderWindow& window, int& numOfLevel)
{
	for (auto& x : m_options)
	{
		if (x.first.getGlobalBounds().contains(location))
		{
			return x.second->execute(window, numOfLevel); // darker
		}
	}
	return true;
}