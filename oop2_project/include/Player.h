#pragma once
#include "MovingObject.h"
#include "PlayerState.h"


class Player : public MovingObject {

public:
	Player(sf::Vector2f location, Resources::Object object);
	virtual ~Player() = default;

	void setPlayer(sf::Vector2f location);
	void updateAnimation(sf::Time delta);
	virtual void handleInput(Input input);
	void setStateAnimation(Direction dir);
	void update(sf::Time delta);
	void setJumping(bool jumping) { m_jumping = jumping; }
	void setOnWall(bool onWall) { m_onWall = onWall; }
	void setGameDate(GameData gameData, int num);
	const int* getGameDate() const { return m_gameDate; };
	bool getFlickering() const { return m_flickering; };
	bool getShotArrow() const { return m_shotArrow; };
	void setShotArrow(bool shot) { m_shotArrow = shot; }
	void reduceLife();
	
	void draw(sf::RenderTarget& window);

private:
	void movePlayer(sf::Time delta);
	void checkIfShotArrow();

	std::unique_ptr<PlayerState> m_state;
	sf::Vector2f m_startPos;
	sf::Clock m_flickerClock;
	sf::Clock m_createBullet;
	sf::Time m_flickerStartTime;
	Animation m_animation;

	bool m_enterExit = false;
	bool m_jumping = false;
	bool m_onWall = true;
	bool m_flickering = false;
	bool m_shotArrow = false;
	bool m_spacePressed = false;

	int m_gameDate[GameData::CountGameData] = { START_LIVES, 0 };
	
};
