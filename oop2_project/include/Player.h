#pragma once
#include "MovingObject.h"
#include "PlayerState.h"


class Player : public MovingObject 
{
public:
	Player(sf::Vector2f location, Resources::Object object);
	virtual ~Player() = default;

	void setPlayer(sf::Vector2f location);
	void updateAnimation(sf::Time delta);
	virtual void handleInput(Input input);
	void setStateAnimation(Direction dir, AnimationState state);
	void update(sf::Time delta);
	void setJumping(bool jumping) { m_jumping = jumping; }
	void setOnWall(bool onWall) { m_onWall = onWall; }
	void setGameData(GameData gameData, int num);
	const std::vector<int>& getGameData() const;
	bool getFlickering() const { return m_flickering; };
	bool getShotArrow() const { return m_shotArrow; };
	void setShotArrow(bool shot) { m_shotArrow = shot; }
	void setSuperSpeed(bool status) { m_superSpeed = status; }
	void setInvincible(bool status) { m_invincible = status; }
	bool getInvincible() const { return m_invincible; }
	bool getSuperSpeed() const { return m_superSpeed; }
	void reduceLife();
	void setFlickering();
	void draw(sf::RenderWindow& window);
	void hittedByEnemy();
	void updatePlayerGiftPowers();
	void movePlayer(sf::Time delta);
	bool isFallingOffTheScreen() const;
	bool isOutOfScreenBounds() const;
private:
	
	void checkIfShotArrow();
	std::unique_ptr<PlayerState> m_state;
	sf::Vector2f m_startPos;
	Animation m_animation;
	sf::Sprite m_bubble;
	bool m_shotArrow = false;
	bool m_spacePressed = false;
	bool m_jumping = false;
	bool m_onWall = true;
	bool m_flickering = false;
	bool m_invincible = false;	//protected?
	bool m_superSpeed = false;	//protected?
	std::vector<int> m_gameData;	
	sf::Time m_delta1;
};
