#pragma once
#include "MovingObject.h"
#include "PlayerState.h"

class Player : public MovingObject {

public:
	Player(sf::Vector2f location, Resources::Object object);
	virtual ~Player() = default;

	void setPlayer(sf::Vector2f location);
	void updateAnimation(sf::Time delta);
	virtual void handleInput(Input input);
	void setStateAnimation(Direction dir);
	void update(sf::Time delta);
private:
	sf::Vector2f m_startPos;
	bool m_enterExit = false;
	std::unique_ptr<PlayerState> m_state;
};
