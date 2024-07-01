#pragma once
#include "Enemy.h"

class RandomEnemy : public Enemy {

public:
	RandomEnemy(sf::Vector2f location, Resources::Object object);
	virtual ~RandomEnemy() = default;
	void update(sf::Time delta);
	bool getChangeDir() const { return m_changeDir; }
	void setChangeDir(bool status) { m_changeDir = status; }

private:
	void move(sf::Time delta);
	void changeDir();

	bool m_changeDir = false;
	Animation m_animation;
};

