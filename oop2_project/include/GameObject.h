#pragma once
#include "Resources.h"
#include "Factory.h"
#include "Direction.h"
#include "Animation.h"

class GameObject
{
public:
	GameObject(sf::Vector2f location, Resources::Object object);
	virtual ~GameObject() = default;

	void draw(sf::RenderTarget& window) const;
	void setCurrPos(sf::Vector2f loc);
	void setIsDead(bool status);
	void setDir(Direction dir) { m_dir = dir; }
	const bool getIsDead() const;
	sf::Sprite getSprite() const;

protected:
	mutable sf::Sprite m_sprite;
	Direction m_dir = Direction::Stay;	
	bool m_isDead = false;
};