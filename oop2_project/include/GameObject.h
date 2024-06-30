#pragma once
#include "Resources.h"
#include "Factory.h"
#include "Direction.h"
#include "Animation.h"

class GameObject {

public:
	GameObject(sf::Vector2f location, Resources::Object object);
	virtual ~GameObject() = default;

	void draw(sf::RenderTarget& window) const;
	void setCurrPos(sf::Vector2f loc);
	sf::Sprite getSprite() const;
	const bool getIsDead() const;
	void setIsDead(bool status);


protected:
	sf::Sprite m_sprite;
	Direction m_dir = Direction::Stay;	
	bool m_isDead = false;

};