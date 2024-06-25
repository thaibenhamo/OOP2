#include "JumpingState.h"
#include "FallingState.h" 

//allocates the actual storage for the static member variable.
std::chrono::steady_clock::time_point JumpingState::m_jumpingTime;

JumpingState::~JumpingState() {}

std::unique_ptr<PlayerState> JumpingState::handleInput(Input input)
{
    
    if (jumpingTimerEnded() || input == RELEASE_JUMP)
    {   
        return std::make_unique<FallingState>(true);      
    }
    
    // so the player could move right or left while jumping
    return std::make_unique<JumpingState>();
}


void JumpingState::enter(Player& player)
{
    player.setStateAnimation(Direction::Up);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.setStateAnimation(Direction::UpLeft);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.setStateAnimation(Direction::UpRight);
    }

    //restartClock - need to make it only when is new state
    if (jumpingTimerEnded() && m_newJump) {
        m_jumpingTime = std::chrono::steady_clock::now();
        m_newJump = false;
    }
}

bool JumpingState::jumpingTimerEnded() const
{
    // Check if the jumping duration has elapsed
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_jumpingTime);

    return elapsedTime >= JUMPING_DURATION;
}

