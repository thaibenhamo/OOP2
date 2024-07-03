#pragma once
#include "Enemy.h"

class FlyingEnemy : public Enemy 
{
public:
	FlyingEnemy(sf::Vector2f location, Resources::Object object);
	virtual ~FlyingEnemy() = default;

	void update(sf::Time delta);
	void changeDir();

private:
	void move(sf::Time delta);
	void chasePlayer();
	float distance(const sf::Vector2f& a, const sf::Vector2f& b) const;

	Animation m_animation;
};

