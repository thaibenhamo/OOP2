#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Controller 
{
public:
    Controller();

    void startGame();
    void handleClick(const sf::Vector2f& mousePosition);

private:
    sf::RenderWindow m_window;
    Board m_board;
 
};
