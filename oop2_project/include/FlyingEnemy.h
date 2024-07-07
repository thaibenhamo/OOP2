#pragma once
#include "Enemy.h"

class FlyingEnemy : public Enemy 
{
public:
	FlyingEnemy(const sf::Vector2f& location, const Resources::Object object);
	virtual ~FlyingEnemy() = default;

	void update(sf::Time delta);
	void changeDir();
	bool isOutOfScreenBounds() const;

private:
	void move(sf::Time delta);
	void chasePlayer();
	float distance(const sf::Vector2f& a, const sf::Vector2f& b) const;

	Animation m_animation;
	sf::Clock m_flyingEnemyClock;
};

