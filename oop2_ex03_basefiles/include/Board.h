#pragma once

#include <set>
#include "Stick.h"
#include "Button.h"
#include "CompareScores.h"

class Board
{
public:
	Board();
	void draw(sf::RenderWindow& window);
	void load(const std::string& filename);
	void updateSticksAbove(Stick& newStick);
	void saveBoard(float TimeLeft);
	void updatePickableSticks();
	int handleMouseClick(const sf::Vector2f& mousePosition);
	int getSticksLeft() const;
	int getScore() const;
	int getSticksRaised() const;
	int getPickableSticks() const;
	float getTimeLeftForLoad() const;
	void update();
	void showHint();

private:
	void addStick(const Stick& stick);
	void loadBoardButtons();

	std::list<Stick> m_sticks;
	std::set<Stick*, CompareScores> m_canBePicked;
	std::set<Stick*>::iterator m_hintIterator;
	std::vector<Button> m_buttons;

	sf::Clock m_hintClock;
	sf::RectangleShape m_background;
	
	bool m_hint;
	bool m_gameOver;
	int m_sticksLeft;
	int m_sticksRaised;
	int m_pickableSticks;
	int m_score;
	float m_loadTime;
};