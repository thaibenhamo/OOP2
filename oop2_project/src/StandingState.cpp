#include "StandingState.h"
#include "MovingState.h" 
#include "JumpingState.h" 

StandingState::StandingState() : PlayerState(Direction::Stay) {}

StandingState::~StandingState()  {}

std::unique_ptr<PlayerState> StandingState::handleInput(Input input) 
{
    if (input == PRESS_LEFT) {
        return std::make_unique<MovingState>(Direction::Left);
    }
    if (input == PRESS_RIGHT) {
        return std::make_unique<MovingState>(Direction::Right);
    }
    if (input == PRESS_UP) {
        return std::make_unique<JumpingState>(true, Direction::Up);        //true as for new jump
    }
    // Stay in this state.
    return nullptr;
}

void StandingState::enter(Player& player) 
{
    player.setStateAnimation(Direction::Stay);
}