#include "Menu.h"
#include "Controller.h"
#include "Macros.h"

Menu::Menu() : m_background(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT))
{
	m_background.setTexture(ResourcesManager::instance().getTexture("menuBackground"));
	loadMenuButtons();
}

void Menu::draw(sf::RenderWindow& window) 
{
	window.draw(m_background);

	for (const auto& button : m_buttons) 
	{
		button.draw(window);
	}
}

void Menu::loadMenuButtons()
{
	m_buttons.push_back(Button(sf::Vector2f(425, 350), sf::Vector2f(350, 60), "Start Game"));
	m_buttons.push_back(Button(sf::Vector2f(425, 440), sf::Vector2f(350, 60), "Load"));
	m_buttons.push_back(Button(sf::Vector2f(425, 530), sf::Vector2f(350, 60), "Exit"));
}

int Menu::handleMouseClick(const sf::Vector2f& mousePosition) 
{
	for (size_t i = 0; i < m_buttons.size(); ++i) 
	{
		if (m_buttons[i].isClicked(mousePosition)) 
		{
			return int(i);
		}
	}
	return -1;
}
