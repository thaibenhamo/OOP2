#include "Board.h"
#include <iostream> //for debug

Board::Board() : m_sticksRaised(0), m_pickableSticks(0)
{
    m_background.setSize(sf::Vector2f(1200, 800));
    m_background.setTexture(ResourcesManager::instance().getTexture("background"));
    m_sticksLeft = 65;
    for (int i = 0; i < 65; i++)
    {
        addStick(Stick());
    }

}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(m_background);
    for (auto& stick : m_sticks) 
    {
        stick.draw(window);
    }
}

void Board::addStick(const Stick& stick)
{
    m_sticks.push_back(stick);

    updateSticksAbove(m_sticks.back());

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

                // Update the list of sticks above other sticks before removing
                for (auto& stick : m_sticks)
                {
                    stick.removeStickAbove(&(*it));
                }

                m_sticksLeft--;
                m_sticksRaised++;
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
    m_pickableSticks = 0;
    for (auto& stick : m_sticks) 
    {
        if (stick.canBePicked()) 
        {
            m_pickableSticks++;
            m_canBePicked.insert(&stick);
        }
    }
}



int Board::getSticksLeft() const 
{
    return m_sticksLeft;
}

int Board::getSticksRaised() const 
{
    return m_sticksRaised;
}

int Board::getPickableSticks() const 
{
    return m_pickableSticks;
}

void Board::update() 
{
    for (auto& stick : m_sticks) 
    {
        stick.update();
    }
}