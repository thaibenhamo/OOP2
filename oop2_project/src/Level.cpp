#pragma once
#include "Level.h"
#include "CollisionHandling.h"
#include "RandomEnemy.h"
#include "FlyingEnemy.h"
#include "Arrow.h"
#include <fstream>


Level::Level()
	: m_player(Player({ 0,0 }, Resources::Player)) {}

void Level::initObjects() 
{
	m_staticObjects.clear();
	m_movingObjects.clear();
}

//to fix so it will be with  exceptions!!!!
void Level::setLevel(const int levelNum) 
{
	initObjects();	//reset all objects
		
	// set level name
	std::string levelName = LEVEL_NAME;
	levelName += std::to_string(levelNum);
	levelName += FILE_EXTENSION;

	std::ifstream file = std::ifstream(levelName);	//open level file

	if (file)
	{
		readLevelFile(file);
	}

	else
	{
		m_winGame = true;		// no more levels to read
	}

	m_winLevel = false;		//for next level/game
}

void Level::readLevelFile(std::ifstream& file) 
{
	auto line = std::string();			// to reads lines from the file

	if (!std::getline(file, line)) 
	{
		throw FileError();
	}

	auto readSize = std::istringstream(line);
	readSize >> m_rows >> m_cols;

	// read the level from the file and create the objects
	for (int i = 0; i < m_rows; i++) 
	{
		if (!std::getline(file, line))
		{
			throw FileError();
		}	

		for (int j = 0; j < line.size(); j++)
		{
			ObjectType objectType = static_cast<ObjectType>(line[j]);
			Resources::Object resourceType = Resources::instance().getResourceType(objectType);

			auto pos = findLocation(i, j);

			auto movingPtr = Factory<MovingObject>::instance().create(objectType, pos, resourceType);
			if (movingPtr)
			{
				m_movingObjects.push_back(std::move(movingPtr));
			}
				
			auto staticPtr = Factory<StaticObject>::instance().create(objectType, pos, resourceType);
			if (staticPtr)
			{
				m_staticObjects.push_back(std::move(staticPtr));
			}	

			if (resourceType == Resources::Player)
			{
				m_player.setPlayer(pos);
			}		
		}
	}
}

void Level::updateStaticObjects()
{
	for (auto& staticObject : m_staticObjects)
	{
		if (typeid(*staticObject) != typeid(Wall))
		{
			if (staticObject->lifeTimerEnded())
			{
				if (!staticObject->getIsFlickering())
				{
					staticObject->startFlickeringTimer();
				}
				else
				{
					staticObject->checkIfStillFlickering();
				}
			}
		}
	}
}

void Level::updateObjects(sf::Time dt) 
{
	m_player.update(dt);
	updateAnimation(dt);

	for (auto& movingObject : m_movingObjects) 
	{
		movingObject->updateWithPlayerPosition(m_player.getPos());
		movingObject->update(dt);
	}

	updateArrow();
	updateStaticObjects();

	collisions();
	eraseIfDead();
}

void Level::updateArrow()
{
	if (m_player.getShotArrow())
	{
		float param = m_player.getSprite().getScale().x;		//shows if player is looking to left or to the right
		sf::Vector2f pos = { m_player.getPos().x + (param * OFFSET_X_FOR_BULLET), 
							 m_player.getPos().y + OFFSET_Y_FOR_BULLET };
		m_movingObjects.emplace_back(std::make_unique<Arrow>(pos, Resources::Arrow, param));
		m_player.setShotArrow(false);

		/*
		//???
		ObjectType objectType = static_cast<ObjectType>('>');
		Resources::Object resourceType = Resources::instance().getResourceType(objectType);
		sf::Vector2f pos = { m_player.getPos().x + OFFSET_X_FOR_BULLET, m_player.getPos().y + OFFSET_Y_FOR_BULLET };
		auto movingPtr = Factory<MovingObject>::instance().create(objectType, pos, resourceType);
		if (movingPtr) {
			m_movingObjects.push_back(std::move(movingPtr));
		}*/
	}
}

void Level::collisions() 
{
	// collide player with static objects
	for (auto& staticObject : m_staticObjects)
	{
		if (collide(m_player, *staticObject))
		{
			processCollision(m_player, *staticObject);
		}
	}
		
	for (auto& movingObject : m_movingObjects)
	{
		if (collide(m_player, *movingObject))
		{
			processCollision(m_player, *movingObject);
		}	
	}

	// collide moving with static objects
	for (auto& m1 : m_movingObjects)
	{
		for (auto& s1 : m_staticObjects)
		{
			if (collide(*m1, *s1))
			{
				processCollision(*m1, *s1);
			}		
		}		
	}
		
	// collide moving with moving objects
	for (auto& m1 : m_movingObjects)
	{
		for (auto& m2 : m_movingObjects)
		{
			if (m1 != m2 and collide(*m1, *m2))
			{
				processCollision(*m1, *m2);
			}	
		}		
	}
}

//to change to game object??
bool Level::collide(MovingObject& a, GameObject& b) const
{
	return a.getSprite().getGlobalBounds().intersects(b.getSprite().getGlobalBounds());
}

void Level::updateAnimation(sf::Time dt) 
{
	m_player.updateAnimation(dt);
}

void Level::eraseIfDead() 
{
	// delete dead objects
	std::erase_if(m_movingObjects, [](auto& movingObject) 
		{
			return movingObject->getIsDead();
		});

	std::erase_if(m_staticObjects, [](auto& staticObject) 
		{
			return staticObject->getIsDead();
		});
}

void Level::drawObjects(sf::RenderWindow& window)
{
	// draw all objects
	for (auto& staticObject : m_staticObjects)
	{
		staticObject->draw(window);
	}
		
	for (auto& movingObject : m_movingObjects)
	{
		movingObject->draw(window);
	}	

	m_player.draw(window);
}

const sf::Vector2f Level::findLocation(const int row, const int col) const 
{
	return sf::Vector2f(OBJECTSIZE_X * col, OBJECTSIZE_Y* row);
}

const bool Level::getWinGame() const
{
	return m_winGame;
}

void Level::handleInput(const Input input)
{
	m_player.handleInput(input);
}

const std::vector<int>& Level::getInfoBarData() const
{
	return m_player.getGameData();
}
	