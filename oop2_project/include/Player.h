#pragma once
#include "MovingObject.h"
#include "PlayerState.h"
#include "Animation.h"

class Player : public MovingObject 
{
public:
	Player(const sf::Vector2f& location, const Resources::Object object);
	virtual ~Player() = default;

	virtual void handleInput(Input input);
	void setPlayer(const sf::Vector2f& location);
	void updateAnimation(sf::Time delta);
	void setStateAnimation(const Direction dir, const AnimationState state);
	void update(sf::Time delta);
	void setJumping(const bool jumping) { m_jumping = jumping; }
	void setOnWall(const bool onWall) { m_onWall = onWall; }
	void setGameData(GameData gameData, const int num);	
	void setLives(const int num) { m_gameData[Lives] = num; }
	void setShotArrow(const bool shot) { m_shotArrow = shot; }
	void setSuperSpeed(const bool status) { m_superSpeed = status; }
	void setInvincible(const bool status) { m_invincible = status; }
	void reduceLife();
	void setFlickering();
	void draw(sf::RenderWindow& window);
	void hittedByEnemy();
	void updatePlayerGiftPowers();
	void movePlayer(sf::Time delta);
	bool isFallingOffTheScreen() const;
	bool isOutOfScreenBounds() const;
	bool getFlickering() const { return m_flickering; };
	bool getShotArrow() const { return m_shotArrow; };
	bool getInvincible() const { return m_invincible; }
	bool getSuperSpeed() const { return m_superSpeed; }
	const std::vector<int>& getGameData() const;

private:
	void checkIfShotArrow();

	Animation m_animation;
	std::unique_ptr<PlayerState> m_state;
	std::vector<int> m_gameData;
	sf::Vector2f m_startPos;
	sf::Sprite m_bubble;
	sf::Time m_delta1;
	bool m_shotArrow = false;
	bool m_spacePressed = false;
	bool m_jumping = false;
	bool m_onWall = true;
	bool m_first = true;
	bool m_flickering = false;
	bool m_invincible = false;	
	bool m_superSpeed = false;	
};
