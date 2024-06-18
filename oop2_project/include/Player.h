#pragma once
#include "MovingObject.h"

class Player : public MovingObject {

public:
	Player(sf::Vector2f location, Resources::Object object);
	virtual ~Player() = default;

	Player(const Player&) = default;
	Player& operator=(const Player&) = default;
	Player(Player&&) = default;
	Player& operator=(Player&&) = default;

	//const bool getEnterExit() const;
private:
	sf::Vector2f m_startPos;
	bool m_enterExit = false;
};
