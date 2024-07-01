#pragma once
#include "PlayerState.h"
#include "Player.h"

// Forward declaration of StandingState
class StandingState;

class FallingState : public PlayerState
{
public:
    FallingState() : PlayerState(Direction::Down) {};
    FallingState(Direction dir) : PlayerState(dir) {};
    ~FallingState();

    std::unique_ptr<PlayerState> handleInput(Input input) override;

    void enter(Player& player) override;

private:
    static std::chrono::steady_clock::time_point m_fallingTime;
};
