#include "StandingState.h"
#include "MovingState.h" 
#include "JumpingState.h" 
#include "FallingState.h" 

StandingState::StandingState() 
    : PlayerState(Direction::Stay) {}

StandingState::~StandingState()  {}

std::unique_ptr<PlayerState> StandingState::handleInput(Input input) 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
    {
        return std::make_unique<JumpingState> (Direction::Up);        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {
        return std::make_unique<MovingState>(Direction::Left, true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        return std::make_unique<MovingState>(Direction::Right, true);
    }
    
    // Stay in this state.
    return nullptr;
}

void StandingState::enter(Player& player) 
{
    player.setStateAnimation(Direction::Stay, AnimationState::Stay);
    player.setJumping(false);
}