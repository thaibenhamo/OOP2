#pragma once
#include "Enemy.h"


class RandomEnemy : public Enemy {

public:
	RandomEnemy(sf::Vector2f location, Resources::Object object);
	virtual ~RandomEnemy() = default;

	RandomEnemy(const RandomEnemy&) = default;
	RandomEnemy& operator=(const RandomEnemy&) = default;
	RandomEnemy(RandomEnemy&&) = default;
	RandomEnemy& operator=(RandomEnemy&&) = default;


private:

};

