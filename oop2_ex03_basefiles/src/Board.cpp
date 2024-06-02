#include <iostream>
#include <fstream>
#include "Board.h"
#include "IncorrectFileException.h"
#include "InvalidGameStateException.h"
#include "Macros.h"

Board::Board() : m_sticksRaised(0), m_pickableSticks(0), m_score(0),
                 m_hint(false), m_gameOver(false), m_loadTime(0)
{
    m_background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    m_background.setTexture(ResourcesManager::instance().getTexture("background"));

    m_sticksLeft = (rand() % (60 - 40 + 1)) + 40;

    for (int i = 0; i < m_sticksLeft; i++)
    {
        addStick(Stick(i));
    }
   
    loadBoardButtons();
    m_hintIterator = m_canBePicked.begin();
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(m_background);
   
    for (auto& stick : m_sticks) 
    {
        stick.draw(window);
    }

    for (auto& button : m_buttons)
    {
       button.draw(window);
    }
}

void Board::loadBoardButtons()
{
    m_buttons.push_back(Button(sf::Vector2f(30, 280), sf::Vector2f(120, 55),
                               "Hint"));
    m_buttons.push_back(Button(sf::Vector2f(30, 350), sf::Vector2f(120, 55),
                               "Save"));
    m_buttons.push_back(Button(sf::Vector2f(30, 420), sf::Vector2f(120, 55),
                               "Quit"));
}


void Board::addStick(const Stick& stick)
{
    m_sticks.push_back(stick);

    updateSticksAbove(m_sticks.back());

    updatePickableSticks();
}

int Board::handleMouseClick(const sf::Vector2f& mousePosition) 
{
   for (auto it = m_sticks.begin(); it != m_sticks.end(); ++it) 
   {
        if (it->contains(mousePosition)) 
        {  
            if(it->canBePicked())
            {
                for (auto& stick : m_sticks)
                {
                    stick.removeStickAbove(&(*it));
                }

                m_sticksLeft--;
                m_sticksRaised++;
                m_score += it->getScore();
                m_sticks.erase(it); 

                updatePickableSticks();

                // Reset the hint process
                m_hintIterator = m_canBePicked.begin();
                m_hint = false;
            }
            else
            {
                it->highlightSticksAbove();
            }
            break;
        } 
   }

   for (size_t i = 0; i < m_buttons.size(); ++i)
   {
       if (m_buttons[i].isClicked(mousePosition))
       {
           return int(i);
       }
   }
   return -1;
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

int Board::getScore() const
{
    return m_score;
}

float Board::getTimeLeftForLoad() const
{
    return m_loadTime;
}

void Board::update() 
{
    for (auto& stick : m_sticks) 
    {
        stick.update();
    }

    if (m_hint && m_hintClock.getElapsedTime().asMilliseconds() >= 500) 
    {
        if (m_hintIterator != m_canBePicked.end()) 
        {
            (*m_hintIterator)->highlightStick();
            ++m_hintIterator;
            m_hintClock.restart();
        }

        else 
        {
            m_hint = false; // No more sticks to highlight
        }
    }
}

void Board::showHint()
{
    m_hintIterator = m_canBePicked.begin();
    m_hintClock.restart();
    m_hint = true;
}

void Board::saveBoard(float timeLeft) 
{
    std::ofstream outFile("Board.txt");

    m_loadTime = timeLeft;

    outFile << m_sticksLeft << '\n' << m_loadTime << '\n' << m_score << '\n'
            << m_sticksRaised << '\n' << m_pickableSticks << '\n';

    for (const auto& stick : m_sticks) 
    {
        stick.save(outFile);
    }
}

void Board::load(const std::string& filename)
{
    std::ifstream inFile(filename);

    if (!inFile.is_open())
    {
        throw IncorrectFileException("Could not open file for loading.");
    }

    if (!(inFile >> m_sticksLeft))
    {
        throw IncorrectFileException("Failed to read the number of sticks.");
    }

    if (!(inFile >> m_loadTime >> m_score >> m_sticksRaised >> m_pickableSticks))
    {
        throw IncorrectFileException("Failed to read board state.");
    }

    if (m_sticksLeft < 0 || m_sticksRaised < 0 || m_pickableSticks < 0 || m_loadTime < 0 || m_score < 0)
    {
        throw InvalidGameStateException("Invalid game state detected.");
    }

    m_sticks.clear();

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the first line

    for (int i = 0; i < m_sticksLeft; ++i)
    {
        Stick stick;
        stick.load(inFile, m_sticksLeft + m_sticksRaised);
        m_sticks.push_back(stick);

        updateSticksAbove(m_sticks.back());
        updatePickableSticks();
    }
    
    m_hintIterator = m_canBePicked.begin();
}    