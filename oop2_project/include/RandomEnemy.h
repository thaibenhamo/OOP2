#pragma once
#include "Enemy.h"

class RandomEnemy : public Enemy {

public:
	RandomEnemy(sf::Vector2f location, Resources::Object object);
	virtual ~RandomEnemy() = default;

private:
};

