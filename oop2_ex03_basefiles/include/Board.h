#pragma once
#include <set>
#include "Stick.h"

class Board
{
public:
	Board();
	void draw(sf::RenderWindow& window) const;
	void handleMouseClick(const sf::Vector2f& mousePosition);
	void addStick(const Stick& stick);
	void updateSticksAbove(Stick& newStick);
	void addStickAbove(Stick* stick);
	void updatePickableSticks();
private:
	std::list<Stick> m_sticks;
	std::set<Stick*> m_canBePicked;
};