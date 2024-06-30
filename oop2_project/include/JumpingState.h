#pragma once
#include "PlayerState.h"
#include "Player.h"

// Forward declaration of StandingState
class StandingState;

class JumpingState : public PlayerState
{

public:
    JumpingState(Direction direction) : PlayerState(direction) {};
    ~JumpingState();

    std::unique_ptr<PlayerState> handleInput(Input input) override;

    void enter(Player& player) override;
    bool jumpingTimerEnded() const;

private:
    static std::chrono::steady_clock::time_point m_jumpingTime;
    //Direction jumpingDirection = Direction::Up;
    bool m_newJump = true;

};
