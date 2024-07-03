#pragma once
#include "StaticObject.h"

class Gift : public StaticObject 
{
public:
	using StaticObject::StaticObject;
	void startGiftTime();

private:
	sf::Clock m_timeGiftClock;
	bool m_isOn = false;
};


