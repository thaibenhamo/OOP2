#pragma once
#include "GameObject.h"

class StaticObject : public GameObject 
{
public:
	StaticObject(const sf::Vector2f& location, const Resources::Object object);
	virtual ~StaticObject() = default;

	bool lifeTimerEnded() const;
	bool getIsFlickering() const;
	void startFlickeringTimer();
	void checkIfStillFlickering();
	void draw(sf::RenderTarget& window) const;
	
private:
	sf::Clock m_lifeClock;
	sf::Clock m_flickeringClock;
	float m_lifeDuration = 10.0f;
	bool m_flickering = false;
};
