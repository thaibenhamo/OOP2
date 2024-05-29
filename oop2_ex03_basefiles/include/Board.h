#pragma once
#include <set>
#include "Stick.h"

class Board
{
public:
	Board();
	void draw(sf::RenderWindow& window);
	void handleMouseClick(const sf::Vector2f& mousePosition);
	void addStick(const Stick& stick);
	void updateSticksAbove(Stick& newStick);
	
	void updatePickableSticks();
	int getSticksLeft() const;
	int getSticksRaised() const;
	int getPickableSticks() const;
	void update();
private:
	sf::RectangleShape m_background;
	std::list<Stick> m_sticks;
	std::set<Stick*> m_canBePicked;
	int m_sticksLeft;
	int m_sticksRaised;
	int m_pickableSticks;
};