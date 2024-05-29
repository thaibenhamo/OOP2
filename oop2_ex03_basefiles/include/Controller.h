#pragma once

#include <SFML/Graphics.hpp>
#include "ToolBar.h"
#include "Board.h"

class Controller 
{
public:
    Controller();

    void startGame();
    void handleClick(const sf::Vector2f& mousePosition);

private:
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    Board m_board;
    ToolBar m_toolBar;
    float m_timeLeft;
    
 
};
