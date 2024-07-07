#pragma once
#include "MenuCommand.h"

class ScoresMenuCommand : public MenuCommand
{
public:
	ScoresMenuCommand();
	virtual bool execute(sf::RenderWindow& window, int& score) override;
	virtual void show(sf::RenderWindow& window) const override;
	virtual void handleMove(const sf::Vector2f& location) override;
	virtual bool handleClick(const sf::Vector2f& location, int& numOfLevel) override;

private:
	std::vector<std::pair<int, sf::Text>> m_scores;
	int m_largestScore = 0;

	void updateValues(int numOfLevel);
	sf::Text setText(int i);
};