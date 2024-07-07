#include "FallingState.h"
#include "StandingState.h" 
#include "MovingState.h" 

FallingState::~FallingState() {}

std::unique_ptr<PlayerState> FallingState::handleInput(Input input)
{
    if (input == RELEASE_ON_WALL)
    {
        return std::make_unique<StandingState>();
    }

    if (input == FALLING_OUT_OF_BOUNDS)
    {
        return std::make_unique<FallingState>(Direction::Down);
    }

    // so the player could move right or left while falling
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && 
        m_direction != Direction::DownLeft)
    {
        return std::make_unique<FallingState>(Direction::DownLeft);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && 
        m_direction != Direction::DownRight)
    {
        return std::make_unique<FallingState>(Direction::DownRight);
    }

    //stay in the state
    return nullptr;
}

void FallingState::enter(Player& player)
{
    player.setStateAnimation(m_direction, AnimationState::Land);
    player.setJumping(false);
}


