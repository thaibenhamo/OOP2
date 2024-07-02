#pragma once
#include "GameObject.h"


class StaticObject : public GameObject {

public:
	StaticObject(sf::Vector2f location, Resources::Object object);
	virtual ~StaticObject() = default;

	bool lifeTimerEnded() const;
	void startFlickeringTimer();
	void checkIfStillFlickering();
	void draw(sf::RenderTarget& window) const;
	bool getIsFlickering() const;

private:
	sf::Clock m_lifeClock;
	sf::Clock m_flickeringClock;
	float m_lifeDuration = 10.0f;
	bool m_flickering = false;

};
