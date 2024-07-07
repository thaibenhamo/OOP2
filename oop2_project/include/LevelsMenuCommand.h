#pragma once
#include "MenuCommand.h"

class LevelsMenuCommand : public MenuCommand
{
public:
	LevelsMenuCommand();

	virtual bool execute(sf::RenderWindow& window, int& numOfLevel) override;
	virtual void show(sf::RenderWindow& window) const override;
	virtual void handleMove(const sf::Vector2f& location) override;
	virtual bool handleClick(const sf::Vector2f& location, sf::RenderWindow& window, int& numOfLevel) override;

private:
	std::vector< std::unique_ptr<Button>> m_levelsButtons;
	bool m_unLock[NUM_OF_LEVELS] = { 0 };
	int m_largestUnLockLevel = 1;

	void updateValues(int numOfLevel);
};