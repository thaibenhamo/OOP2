#pragma once
#include "Resources.h"
#include "Player.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "Factory.h"

class Level 
{
public:
	Level();
	virtual ~Level() = default;

	void setLevel(const int LevelNum);
	void drawObjects(sf::RenderWindow& window);
	const bool getWinGame() const;
	void updateObjects(sf::Time dt);
	void handleInput(const Input input);
	const std::vector<int>& getInfoBarData() const;
private:
	void updateAnimation(sf::Time dt);
	const sf::Vector2f findLocation(const int row, const int col) const;
	void initObjects();
	void readLevelFile(std::ifstream& file);
	void collisions();
	bool collide(MovingObject& a, GameObject& b) const;
	void eraseIfDead();

	Player m_player;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects; //store static objects
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects; //store moving objects

	int m_rows = DEFAULT_ROWS;		//num of rows in board
	int m_cols = DEFAULT_COLS;		//num of cols in board
	bool m_winLevel = false;		//if win level
	bool m_winGame = false;			//if win game

};
