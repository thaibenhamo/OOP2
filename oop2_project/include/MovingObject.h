#pragma once
#include "GameObject.h"
#include "Direction.h"
#include "Animation.h"

class MovingObject : public GameObject 
{
public:
	MovingObject(const sf::Vector2f& location, const Resources::Object object);
	virtual ~MovingObject() = default;

	virtual void update(sf::Time delta) = 0;
	virtual void setDir(const Direction dir) { m_dir = dir; }

	void setPrevLoc(const sf::Vector2f& prevLoc);
	void setPos(const sf::Vector2f& pos);
	void updateWithPlayerPosition(const sf::Vector2f& playerPosition) { m_playerPosition = playerPosition; }
	bool getMakeCoin() const { return m_makeCoin; }
	void setMakeCoin() { m_makeCoin = true; }
	const sf::Vector2f getPrevLoc() const;
	const sf::Vector2f getPos() const;
	Direction getDir() const { return m_dir; }

protected:
	sf::Vector2f m_playerPosition;
	sf::Vector2f m_prevLocation;	//to store previos location
	Direction m_dir = Direction::Stay;
	bool m_makeCoin = false;
};