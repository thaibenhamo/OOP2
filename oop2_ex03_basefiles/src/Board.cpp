#include "Board.h"
#include <iostream> //for debug
Board::Board() 
{
    for (int i = 0; i < 37; i++)
    {
        addStick(Stick());
        //m_sticks.push_back(Stick());
    }

}

void Board::draw(sf::RenderWindow& window) const
{
    for (const auto& stick : m_sticks) 
    {
        stick.draw(window);
    }
}

void Board::addStick(const Stick& stick) 
{
    m_sticks.push_back(stick);

    if (!m_sticks.empty()) 
    {
        updateSticksAbove(m_sticks.back());
    }
    updatePickableSticks();
}

void Board::handleMouseClick(const sf::Vector2f& mousePosition) 
{
   for (auto it = m_sticks.begin(); it != m_sticks.end(); ++it) 
   {
        if (it->contains(mousePosition)) 
        {
            // Check if the stick can be picked
            if (!it->canBePicked()) 
            {
                it->checkAndFlickerAboveSticks();
            }
            else 
            {
                std::cout << "Stick picked up at position: (" << it->getStartPoint().x << ", " << it->getStartPoint().y << ")\n";

                // Remove stick from m_sticks and update the state
                it = m_sticks.erase(it); // Erase the stick and advance the iterator
                updatePickableSticks();
            }
            break; // No need to check other sticks
        }
    }
}

void Board::updateSticksAbove(Stick& newStick) 
{
    for (auto& stick : m_sticks) 
    {
        if (&stick != &newStick && stick.intersects(newStick)) 
        {
            stick.addStickAbove(&newStick);
        }
    }
}

void Board::updatePickableSticks() 
{
    m_canBePicked.clear();
    for (auto& stick : m_sticks) 
    {
        if (stick.canBePicked()) 
        {
            m_canBePicked.insert(&stick);
        }
    }
}

void Stick::addStickAbove(Stick* stick) 
{
    m_sticksAbove.push_back(stick);
}
