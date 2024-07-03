#pragma once

#include "FileError.h"
#include <vector>
#include "Macros.h"
#include "AnimationData.h"

class Resources 
{
public:
	enum Object
	{
		Player = ButtonType::CountButton,
		Wall,
		Coin, 
		Arrow,
		BubbleGift,
		LifeGift,
		SpeedGift,
		Bubble,
		RandomEnemy,
		FlyingEnemy,
		ScoreDisplay,
		LivesDisplay,
		Heart1,
		Heart2,
		Heart3,
		Space,
		Max
	};

	//Singleton, provides a centralized access point to these resources.
	static Resources& instance() 
	{
		static auto resources = Resources(); 
		return resources;
	}

	//delete copy c-tor and operator=
	Resources(const Resources&) = delete;
	void operator=(const Resources&) = delete;

	sf::Texture& get(const Object object);
	sf::Texture& get(const BackgroundType type);
	sf::Texture& get(const ButtonType buttonType);
	sf::Font& getFont();
	const sf::Texture& texture() const { return m_textures[5]; } // temporary
	Resources::Object getResourceType(ObjectType type);	// Mapping from ObjectType to Resources::Object
	AnimationData& animationData(Object object) { return m_data[object]; } // temporary

private:
	Resources();
	std::vector<sf::Texture> m_textures;	//to store all game textures
	std::vector<AnimationData> m_data;
	sf::Font m_font; // vector if we need more
};
