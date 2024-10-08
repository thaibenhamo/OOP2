#pragma once

#include "Macros.h"
#include "InfoBar.h"
#include "Board.h"
#include "Menu.h"

class Controller 
{
public:
    Controller();
    void run();
    void startGame();

private:
    void handleBoardClick(const sf::Vector2f& mousePosition);
    void handleMenuClick(const sf::Vector2f& mousePosition);
    void startMenu();
    void endScreen();

    sf::RenderWindow m_window;
    sf::Clock m_clock;

    Menu m_menu;
    Board m_board;
    InfoBar m_infoBar;

    float m_timeLeft;
   
};
