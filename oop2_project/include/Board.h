#pragma once
#include "Resources.h"
#include "Player.h"
#include "Macros.h"
#include "MovingObject.h"

class Board {

public:
	Board();
	virtual ~Board() = default;

	void setBoard(const int LevelNum);
	void drawObjects(sf::RenderWindow& window) const;
	const bool getWinGame() const;
	const bool getWinLevel() const;
private:
	const sf::Vector2f findLocation(const int row, const int col) const;
	void initObjects();
	void readLevelFile(std::ifstream& file);
	void createObject(const ObjectType type, const sf::Vector2f location);
	std::unique_ptr<Player> m_player;
	//std::vector<std::unique_ptr<StaticObjects>> m_staticObjects; //store static objects
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects; //store moving objects

	int m_rows = DEFAULT_ROWS;		//num of rows in board
	int m_cols = DEFAULT_COLS;		//num of cols in board
	bool m_winLevel = false;		//if win level
	bool m_winGame = false;			//if win game

};
