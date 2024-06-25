#include "FallingState.h"
#include "StandingState.h" 
#include "MovingState.h" 

//allocates the actual storage for the static member variable.
std::chrono::steady_clock::time_point FallingState::m_fallingTime;

FallingState::~FallingState() {}

std::unique_ptr<PlayerState> FallingState::handleInput(Input input)
{
    
    // Compare elapsed time with jumping duration
    if (fallingTimerEnded() && input == RELEASE_DOWN)
    {
        return std::make_unique<StandingState>();
    }
    // so the player could move right or left while falling
    return std::make_unique<FallingState>();
}


void FallingState::enter(Player& player)
{
    player.setStateAnimation(Direction::Down);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.setStateAnimation(Direction::DownLeft);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.setStateAnimation(Direction::DownRight);
    }

    //restartClock
    if (fallingTimerEnded() && m_newFall) {
        m_fallingTime = std::chrono::steady_clock::now();
        m_newFall = false;
    }

}

bool FallingState::fallingTimerEnded() const
{
    // Check if the jumping duration has elapsed
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_fallingTime);

    return elapsedTime >= JUMPING_DURATION;
}
