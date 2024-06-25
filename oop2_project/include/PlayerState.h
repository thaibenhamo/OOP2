#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <SFML/Window/Keyboard.hpp>
#include "Direction.h"

class Player;

enum Input
{
	PRESS_UP,
	PRESS_DOWN,
	PRESS_LEFT,
	PRESS_RIGHT,
	RELEASE_WALK,
	RELEASE_DOWN,
	RELEASE_JUMP
};

class PlayerState {
public:
	PlayerState(Direction dir) : m_direction(dir) { }
	virtual ~PlayerState() { }

	virtual std::unique_ptr<PlayerState> handleInput(Input input) = 0;
	virtual void enter(Player& player) = 0;
	virtual const Direction getDirection() { return m_direction; }
protected:
	Direction m_direction;
};