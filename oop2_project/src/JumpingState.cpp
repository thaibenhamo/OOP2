#include "JumpingState.h"
#include "FallingState.h" 

//allocates the actual storage for the static member variable.
std::chrono::steady_clock::time_point JumpingState::m_jumpingTime;

JumpingState::~JumpingState() {}

std::unique_ptr<PlayerState> JumpingState::handleInput(Input input)
{ 
    if (jumpingTimerEnded() || 
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {   
        return std::make_unique<FallingState>();      
    }

    // so the player could move right or left while jumping
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && 
        m_direction != Direction::UpLeft) 
    {
        return std::make_unique<JumpingState>(Direction::UpLeft);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && 
        m_direction != Direction::UpRight)
    {
        return std::make_unique<JumpingState>(Direction::UpRight);
    }

    //stay in the state
    return nullptr;
}

void JumpingState::enter(Player& player)
{ 
    player.setStateAnimation(m_direction, AnimationState::Jump);

    if (m_newJump) 
    {
        //restartClock - need to make it only when is new state
        if (jumpingTimerEnded()) 
        {
            m_jumpingTime = std::chrono::steady_clock::now();
            m_newJump = false;
            player.setJumping(true);
        }
    }
}

bool JumpingState::jumpingTimerEnded() const
{
    // Check if the jumping duration has elapsed
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_jumpingTime);

    return elapsedTime >= JUMPING_DURATION;
}

