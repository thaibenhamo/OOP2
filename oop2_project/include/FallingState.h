#pragma once
#include "PlayerState.h"
#include "Player.h"

// Forward declaration of StandingState
class StandingState;

class FallingState : public PlayerState
{
public:

    FallingState() : PlayerState(Direction::Down) {};
    FallingState(bool newFall) : PlayerState(Direction::Down), m_newFall(newFall) {};
    ~FallingState();

    std::unique_ptr<PlayerState> handleInput(Input input) override;

    void enter(Player& player) override;
    bool fallingTimerEnded() const;

private:
    static std::chrono::steady_clock::time_point m_fallingTime;
    bool m_newFall = false;

};
