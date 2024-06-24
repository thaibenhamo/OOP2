#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "Direction.h"

class Player;

enum Input
{
	PRESS_UP,
	PRESS_DOWN,
	PRESS_LEFT,
	PRESS_RIGHT
};

class PlayerState {
public:
	virtual ~PlayerState() { }

	virtual std::unique_ptr<PlayerState> handleInput(Input input) = 0;
	virtual void enter(Player& player) = 0;
};