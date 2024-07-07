#pragma once
#include "PlayerState.h"
#include "Player.h"

class MovingState;

class StandingState : public PlayerState
{
public:
    StandingState();
    ~StandingState();

    std::unique_ptr<PlayerState> handleInput(Input input) override;

    void enter(Player& player) override;
   
private:
};
