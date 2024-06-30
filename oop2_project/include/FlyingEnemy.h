#pragma once
#include "Enemy.h"

class FlyingEnemy : public Enemy {

public:
	FlyingEnemy(sf::Vector2f location, Resources::Object object);
	virtual ~FlyingEnemy() = default;
	void update(sf::Time delta);
private:
	void move(sf::Time delta);
};

