#pragma once
#include "Resources.h"
#include "Player.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "Factory.h"
#include "Wall.h"

class Level 
{
public:
	Level();
	virtual ~Level() = default;

	void setLevel(const int LevelNum);
	void drawObjects(sf::RenderWindow& window);
	void updateObjects(sf::Time dt);
	void handleInput(const Input input);
	const std::vector<int>& getInfoBarData() const;
	bool getWinLevel() const { return m_winLevel; }
	bool getLoseLevel() const { return m_loseLevel; }
	void setLoseLevel(bool status) { m_loseLevel = status; }
	void updateWinOrLose();

private:
	void updateAnimation(sf::Time dt);
	const sf::Vector2f findLocation(const int row, const int col) const;
	void initObjects();
	void readLevelFile(std::ifstream& file);
	void collisions();
	bool collide(MovingObject& a, GameObject& b) const;
	void eraseIfDead();
	void updateArrow();
	void updateStaticObjects();


	Player m_player;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects; //store static objects
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects; //store moving objects

	int m_rows = DEFAULT_ROWS;		//num of rows in board
	int m_cols = DEFAULT_COLS;		//num of cols in board
	bool m_winLevel = false;		//if win level
	bool m_loseLevel = false;		//if lose level
	int m_numOfEnemies = 0;

};
