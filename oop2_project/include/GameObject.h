#pragma once
#include "Resources.h"
#include "Factory.h"

class GameObject
{
public:
	GameObject(const sf::Vector2f& location/*, const Resources::Object object*/);
	virtual ~GameObject() = default;

	void draw(sf::RenderWindow& window) const;
	void setIsDead(const bool status);
	const bool getIsDead() const;
	sf::Sprite getSprite() const;

protected:
	mutable sf::Sprite m_sprite;
	bool m_isDead = false;
};