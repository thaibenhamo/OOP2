#pragma once
#include "GameObject.h"
#include "StaticObject.h"
#include "Factory.h"
//#include <iostream> // for debug

StaticObject::StaticObject(const sf::Vector2f& location, const Resources::Object object)
	: GameObject(location /*, object*/)
{
	m_sprite.setTexture(Resources::instance().get(object));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
					   m_sprite.getGlobalBounds().height / 2.f);

	m_lifeClock.restart();
	m_lifeDuration = float((rand() % int(MAX_STATIC_LIFE_DURATION))) + MIN_STATIC_LIFE_DURATION;
}

bool StaticObject::lifeTimerEnded() const
{
	return m_lifeClock.getElapsedTime().asSeconds() >= m_lifeDuration;
}

void StaticObject::startFlickeringTimer()
{
	m_flickeringClock.restart();
	m_flickering = true;

}

void StaticObject::checkIfStillFlickering()
{
	if (m_flickeringClock.getElapsedTime().asSeconds() >= FLICKERING_DURATION)
	{
		m_isDead = true;
	}
}

void StaticObject::draw(sf::RenderTarget& window) const
{
	if (m_flickering)
	{
		if (m_sprite.getColor() == sf::Color::Transparent)
			m_sprite.setColor(sf::Color::White);
		else
			m_sprite.setColor(sf::Color::Transparent);
	}

	window.draw(m_sprite);
}

bool StaticObject::getIsFlickering() const
{
	return m_flickering;
}