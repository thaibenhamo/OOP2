#pragma once
#include "PlayerState.h"
#include "Player.h"

class LeftState : public PlayerState
{
public:
	~LeftState() {}

	std::unique_ptr<PlayerState> handleInput(Input input) {

		if (input == PRESS_RIGHT)
		{
			//return make_unique<RightState>();
		}

		// Stay in this state.
		return NULL;
	}

	virtual void enter(Player& player)
	{
		player.setStateAnimation(Direction::Left);
	}
};