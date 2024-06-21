#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {

public:
	MovingObject(sf::Vector2f location, Resources::Object object);
	virtual ~MovingObject() = default;

	const sf::Vector2f getPrevLoc() const;
	const sf::Vector2f getPos() const;
	void setPrevLoc(const sf::Vector2f prevLoc);
	void setPos(sf::Vector2f pos);

protected:
	sf::Vector2f m_prevLocation;	//to store previos location
	sf::Clock m_clock;

};