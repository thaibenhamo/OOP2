#pragma once
#include "Board.h"

Board::Board() 
	: m_player(Player({ 0,0 }, Resources::Player)) {}

void Board::initObjects() {

	m_staticObjects.clear();
	m_movingObjects.clear();
}

//to fix so it will be with  exceptions!!!!
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

void Board::readLevelFile(std::ifstream& file) {

	auto line = std::string();			// to reads lines from the file

	if (!std::getline(file, line)) {
		throw FileError();
	}

	auto readSize = std::istringstream(line);
	readSize >> m_rows >> m_cols;

	// read the level from the file and create the objects
	for (int i = 0; i < m_rows; i++) 
	{
		if (!std::getline(file, line)) 
			throw FileError();

		for (int j = 0; j < line.size(); j++)
		{
			auto pos = findLocation(i, j);
			ObjectType objectType = static_cast<ObjectType>(line[j]);
			Resources::Object resourceType = Resources::instance().getResourceType(objectType);

			/*auto movingPtr = Factory<MovingObject>::instance().create(objectType, pos, resourceType);
			if (movingPtr) {
				m_movingObjects.push_back(std::move(movingPtr));
			}

			auto staticPtr = Factory<StaticObjects>::instance().create(objectType, pos, resourceType);
			if (staticPtr) {
				m_staticObjects.push_back(std::move(staticPtr));
			}*/

			if (resourceType == Resources::Player) {
				m_player.setPlayer(pos);
			}
		}
	}
}

void Board::updateObjects(sf::Time dt) {

	m_player.update(dt);
	
	//movePlayer(delta);
    // handle collisions
	updateAnimation(dt);
}

void Board::updateAnimation(sf::Time dt) {

	m_player.updateAnimation(dt);
}

void Board::drawObjects(sf::RenderWindow& window) const {

	// draw all objects
	for (auto& staticObject : m_staticObjects)
		staticObject->draw(window);

	for (auto& movingObject : m_movingObjects)
		movingObject->draw(window);

	m_player.draw(window);
}

const sf::Vector2f Board::findLocation(const int row, const int col) const {

	return sf::Vector2f(OBJECTSIZE_X * col, OBJECTSIZE_Y * row);
}

const bool Board::getWinGame() const {

	return m_winGame;
}

void Board::playerDir(const Input input)
{
	m_player.handleInput(input);

}
	