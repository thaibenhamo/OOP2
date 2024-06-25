#pragma once
#include "PlayerState.h"
#include "Player.h"

// Forward declaration of StandingState
class StandingState;

class MovingState : public PlayerState
{
public:
    MovingState(Direction dir);

    ~MovingState();

    std::unique_ptr<PlayerState> handleInput(Input input) override;

    void enter(Player& player) override;
    

private:
    //Direction m_direction;
};
