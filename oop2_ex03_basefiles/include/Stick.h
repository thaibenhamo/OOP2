#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcesManager.h"

class Stick
{
public:
	Stick();
	void draw(sf::RenderWindow& window) const;
	bool contains(const sf::Vector2f& point) const;
	void tryRemoveStick(const sf::Vector2f& mousePosition);
	bool intersects(const Stick& other) const;
	sf::Vector2f getStartPoint() const;
	sf::Vector2f getEndPoint() const;
	void addStickAbove(Stick* stick);
	bool canBePicked() const;
	void flicker();
	void checkAndFlickerAboveSticks();
	void removeStickAbove(Stick* stick);
private:
	sf::Sprite m_stick;
	int m_score;
	std::list<Stick*> m_sticksAbove;
};