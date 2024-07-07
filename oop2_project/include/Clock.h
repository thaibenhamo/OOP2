#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // for std::system()
#include <fstream>

class Clock
{
public:
    Clock() {};
    Clock(const Clock& /*other*/) = delete;
    Clock& operator= (const Clock& /*other*/) = delete;
    static Clock& instance();
    sf::Clock& getBubbleGiftClock();
    sf::Clock& getSpeedGiftClock();
    sf::Clock& getflickerPlayerClock();
    sf::Clock& getShootClock();
    sf::Clock& getSmartEnemyClock();
    sf::Clock& getRandomEnemyClock();

private:
    ~Clock() {};
    sf::Clock m_flickerPlayerClock;
    sf::Clock m_bubbleGiftClock;
    sf::Clock m_shootClock;
    sf::Clock m_speedGiftClock;
    sf::Clock m_randomEnemyClock;
    sf::Clock m_smartEnemyClock;


};