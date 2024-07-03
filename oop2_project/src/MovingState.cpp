#include "MovingState.h"
#include "StandingState.h" 
#include "JumpingState.h" 
#include "FallingState.h" 

MovingState::MovingState(Direction dir, bool newDirection) 
    : PlayerState(dir), m_newDirection(newDirection) {}

MovingState::~MovingState() {}

std::unique_ptr<PlayerState> MovingState::handleInput(Input input) 
{
    if (input == RELEASE_DOWN)
        return std::make_unique<FallingState>();
  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return std::make_unique<JumpingState>(Direction::Up);        

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return std::make_unique<MovingState>(Direction::Right, true);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return std::make_unique<MovingState>(Direction::Left, true);

    // Stop walking.
    return std::make_unique<StandingState>();
}

void MovingState::enter(Player& player) 
{   
    if (m_newDirection) 
    {
        player.setStateAnimation(m_direction, AnimationState::Move);
        player.setJumping(false);
        m_newDirection = false;
    }
}


