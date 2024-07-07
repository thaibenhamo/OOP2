#pragma once
#include "Enemy.h"

class RandomEnemy : public Enemy 
{
public:
	RandomEnemy(const sf::Vector2f &location, const Resources::Object object);
	virtual ~RandomEnemy() = default;

	void update(sf::Time delta);
	void setChangeDir(bool status) { m_changeDir = status; }
	bool getChangeDir() const { return m_changeDir; }

private:
	void move(sf::Time delta);
	bool m_changeDir = false;
	Animation m_animation;
	sf::Clock m_randomEnemyClock;
};

