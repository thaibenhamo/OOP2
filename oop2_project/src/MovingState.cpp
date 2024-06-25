#include "MovingState.h"
#include "StandingState.h" 
#include "JumpingState.h" 


MovingState::MovingState(Direction dir) : PlayerState(dir) {}

MovingState::~MovingState() {}

std::unique_ptr<PlayerState> MovingState::handleInput(Input input) 
{
    if (input == PRESS_RIGHT  && m_direction != Direction::Right) {
        return std::make_unique<MovingState>(Direction::Right);
    }

    if (input == PRESS_LEFT /* && m_direction != Direction::Left*/) {
        return std::make_unique<MovingState>(Direction::Left);
    }

    if (input == PRESS_UP) {
        return std::make_unique<JumpingState>(true, Direction::Up);        //true as for new jump
    }

    if (input == RELEASE_WALK) {
        return std::make_unique<StandingState>();
    }

    // Stay in this state.
    return nullptr;
}

void MovingState::enter(Player& player) 
{
    if (m_direction == Direction::Left)
        player.setStateAnimation(Direction::Left);
    if (m_direction == Direction::Right)
        player.setStateAnimation(Direction::Right);
}


