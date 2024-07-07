#include "Clock.h"

Clock& Clock::instance()
{
	static Clock inst;
	return inst;
}

sf::Clock& Clock::getBubbleGiftClock() 
{
	return m_bubbleGiftClock;
}

sf::Clock& Clock::getflickerPlayerClock()
{
    return m_flickerPlayerClock;
}

sf::Clock& Clock::getShootClock()
{
    return m_shootClock;
}

sf::Clock& Clock::getSpeedGiftClock()
{
	return m_speedGiftClock;
}

sf::Clock& Clock::getJumpingClock()
{
	return m_jumpingClock;
}
