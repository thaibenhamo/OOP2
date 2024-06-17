#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {

public:
	MovingObject(sf::Vector2f location, Resources::Object object);
	virtual ~MovingObject() = default;

	MovingObject(const MovingObject&) = default;
	MovingObject& operator=(const MovingObject&) = default;
	MovingObject(MovingObject&&) = default;
	MovingObject& operator=(MovingObject&&) = default;

	const sf::Vector2f getPrevLoc() const;
	const sf::Vector2f getPos() const;
	//const State getState() const;
	void setPrevLoc(const sf::Vector2f prevLoc);
	void setPos(sf::Vector2f pos);

	//virtual void update(sf::Time delta) { m_animation.update(delta); }

protected:
	sf::Vector2f m_prevLocation;	//to store previos location
	sf::Clock m_clock;

};