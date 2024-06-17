#pragma once
#include "Resources.h"

class GameObject {

public:
	GameObject(sf::Vector2f location, Resources::Object object);
	virtual ~GameObject() = default;

	GameObject(const GameObject&) = default;
	GameObject& operator=(const GameObject&) = default;
	GameObject(GameObject&&) = default;
	GameObject& operator=(GameObject&&) = default;

	void draw(sf::RenderTarget& target);
	void setCurrPos(sf::Vector2f loc);
	sf::Sprite getSprite() const;
	//void state(sf::Keyboard::Key key);
	//const bool getIsDead() const;
	//void setIsDead(bool status);

protected:
	sf::Sprite m_sprite;
	//State m_dir = State::Stay;
	//Animation m_animation;
	//bool m_isDead = false;

};