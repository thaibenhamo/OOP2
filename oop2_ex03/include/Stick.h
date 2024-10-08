#pragma once

#include <SFML/Graphics.hpp>
#include "ResourcesManager.h"

class Stick
{
public:
	Stick(int id);
	Stick();
	void draw(sf::RenderWindow& window);
	bool contains(const sf::Vector2f& point) const;
	bool intersects(const Stick& other) const;
	sf::Vector2f getStartPoint() const;
	sf::Vector2f getEndPoint() const;
	void addStickAbove(Stick* stick);
	bool canBePicked() const;
	void highlightStick();
	void highlightSticksAbove();
	void removeStickAbove(Stick* stickAbove);
	void update();
	int getScore() const;
	int getId() const;
	bool getHighlightStatus() const;
	void save(std::ofstream& outFile) const;

	void load(std::ifstream& inFile, int numOfSticks);
private:
	void setStickScoreByColorIndex(int colorIndex);
	sf::RectangleShape m_stick;
	sf::Clock m_highlightClock;

	int m_score;
	int m_length;
	float m_angle;
	bool m_highlight;
	int m_id;
	int m_color;
	sf::Vector2f m_startPoint;
	std::list<Stick*> m_sticksAbove;
};
