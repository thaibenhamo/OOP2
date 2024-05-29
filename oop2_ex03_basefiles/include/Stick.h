#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcesManager.h"

class Stick
{
public:
	Stick();
	void draw(sf::RenderWindow& window);
	bool contains(const sf::Vector2f& point) const;
	void tryRemoveStick(const sf::Vector2f& mousePosition);
	bool intersects(const Stick& other) const;
	sf::Vector2f getStartPoint() const;
	sf::Vector2f getEndPoint() const;
	void addStickAbove(Stick* stick);
	bool canBePicked() const;
	void flicker();
	void checkAndFlickerAboveSticks();
	void removeStickAbove(Stick* stickAbove);
	void update();
private:
	sf::RectangleShape m_stick;
	sf::Clock m_flickerClock;
	int m_score;
	int m_length;
	int m_angle;
	bool m_highlight;
	sf::Vector2f m_startPoint;
	std::list<Stick*> m_sticksAbove;
};