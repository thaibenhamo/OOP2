#pragma once
#include "MenuCommand.h"

class HelpMenuCommand : public MenuCommand
{
public:
	HelpMenuCommand();
	virtual bool execute(sf::RenderWindow& window, int& numOfLevel) override;
	virtual void show(sf::RenderWindow& window) const override;
	virtual void handleMove(const sf::Vector2f& location) override;
	virtual bool handleClick(const sf::Vector2f& location, int& numOfLevel) override;

private:
};