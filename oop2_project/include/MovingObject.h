#pragma once
#include "GameObject.h"

class MovingObject : public GameObject 
{
public:
	MovingObject(sf::Vector2f location, Resources::Object object);
	virtual ~MovingObject() = default;
	const sf::Vector2f getPrevLoc() const;
	const sf::Vector2f getPos() const;
	void setPrevLoc(const sf::Vector2f prevLoc);
	void setPos(sf::Vector2f pos);
	void updateWithPlayerPosition(const sf::Vector2f& playerPosition) { m_playerPosition = playerPosition; }
	virtual void update(sf::Time delta) = 0;
	virtual void setDir(Direction dir) { m_dir = dir; }
	Direction getDir() const { return m_dir; }
	bool getMakeCoin() const { return m_makeCoin; }
	void setMakeCoin() { m_makeCoin = true; }

protected:
	sf::Vector2f m_playerPosition;
	sf::Vector2f m_prevLocation;	//to store previos location
	Direction m_dir = Direction::Stay;
	bool m_makeCoin = false;
	//Animation m_animation;
};