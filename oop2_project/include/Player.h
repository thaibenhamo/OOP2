#pragma once
#include "MovingObject.h"

class Player : public MovingObject {

public:
	Player(sf::Vector2f location, Resources::Object object);
	virtual ~Player() = default;

	void setPlayer(sf::Vector2f location);
	void updateAnimation(sf::Time delta);

private:
	sf::Vector2f m_startPos;
	bool m_enterExit = false;
};
