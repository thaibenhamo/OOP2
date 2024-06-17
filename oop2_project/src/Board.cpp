#pragma once
#include "Board.h"
#include "Macros.h"

Board::Board()
{}
//=========================================================
void Board::initObjects() {

	//m_staticObjects.clear();
	m_movingObjects.clear();
}
//=========================================================
//to fix so it will be with  exceptions!
void Board::setBoard(const int levelNum) {

	initObjects();	//reset all objects

	// set level name
	std::string levelName = LEVEL_NAME;
	levelName += std::to_string(levelNum);
	levelName += FILE_EXTENSION;

	std::ifstream file = std::ifstream(levelName);	//open level file
	if (file)
		readLevelFile(file);
	else
		m_winGame = true;		// no more levels to read

	m_winLevel = false;		//for next level/game
}

//=========================================================
//to fix so it will be with  exceptions!
void Board::readLevelFile(std::ifstream& file) {

	auto line = std::string();			// to reads lines from the file

	if (!std::getline(file, line)) {
		std::cerr << "Can't read from file1\n";
		exit(EXIT_FAILURE);
	}

	auto readSize = std::istringstream(line);
	readSize >> m_rows >> m_cols;

	// read the level from the file and create the objects
	for (int i = 0; i < m_rows; i++) {
		if (!std::getline(file, line)) {
			std::cerr << "Can't read from file2\n";
			exit(EXIT_FAILURE);
		}
		for (int j = 0; j < line.size(); j++)
			createObject(ObjectType(line[j]), findLocation(i, j));
	}
}

void Board::createObject(const ObjectType type, const sf::Vector2f location) {

	switch (type)
	{
		// characters
	case ObjectType::PlayerChar:
		m_player = std::make_unique<Player>(location, Resources::Player);
		break;
	}
}


//=========================================================
void Board::drawObjects(sf::RenderWindow& window) const {

	// draw all objects

	// for (auto& staticObject : m_staticObjects)
	//	staticObject->draw(window);

	// for (auto& movingObject : m_movingObjects)
	//	movingObject->draw(window);

	m_player->draw(window);
}

//=========================================================
const sf::Vector2f Board::findLocation(const int row, const int col) const {

	sf::Vector2f location;
	location.x = OBJECTSIZE_X * col;
	location.y = OBJECTSIZE_Y * row;
	return location;
}

//=========================================================
const bool Board::getWinGame() const {

	return m_winGame;
}

//=========================================================
const bool Board::getWinLevel() const {

	return m_player->getEnterExit();
}

