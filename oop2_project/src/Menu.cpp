#include "Menu.h"
#include "Button.h"

Menu::Menu()
{
	//m_options.emplace_back(option(0, std::make_unique<LevelsMenuCommand>());
	//m_options.emplace_back(option(1, std::make_unique<HelpMenuCommand>());

	for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
	{
		m_buttons.emplace_back(std::make_unique<Button>(sf::Vector2f(175, 50), i));
		m_buttons[i]->setPosition({ 750.f, float(500 + 80 * i) });
	}
}

void Menu::activate(sf::RenderWindow &window)
{
	show(window);
	//handleEvents(window) - move, click, exit
}

void Menu::show(sf::RenderWindow &window)
{
	window.clear();

	//לעשות את זה בבנאי עם עננים ורץ על לולאה
	auto sprite = sf::Sprite(Resources::instance().get(BackgroundType::Background1));
	window.draw(sprite);
	auto sprite2 = sf::Sprite(Resources::instance().get(BackgroundType::MenuBackground));
	sprite2.setPosition({ 400.f, 100.f });
	window.draw(sprite2);

	for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
		m_buttons[i]->draw(window);

	window.display();

	while (window.isOpen()) {

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				exit(EXIT_SUCCESS);
				break;
			case sf::Event::MouseMoved:
				//handleMouseMove(window);
				break;
			case sf::Event::MouseButtonReleased:
				//if (event.mouseButton.button == sf::Mouse::Button::Left)
					//handleMenuClick(inMenu, window);
				break;
			}
		}
	}

}

//void Menu::handleEvents(window)
//{
//		loop that checks mouse move, click, exit
//			if move - do on the button setLooks
//			if click - do on options execute()
//		 
//}