#pragma once
#include "PlayerState.h"
#include "Player.h"
#include "LeftState.h"

class StandingState : public PlayerState 
{
public:
	~StandingState() {}

	std::unique_ptr<PlayerState> handleInput(Input input) {

		if (input == PRESS_LEFT)
		{
			return std::make_unique<LeftState>();
		}

		// Stay in this state.
		return NULL;
	}

	virtual void enter(Player& player)
	{
		player.setStateAnimation(Direction::Stay);
	}
};