#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <thread>
#include <vector>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>   
#include <list>
#include <stdexcept>
#include "Macros.h"
#include "FileError.h"
#include "AnimationData.h"
#include "Direction.h"

class Resources 
{
public:
	enum Object
	{
		Player = BackgroundType::Count,
		Wall,
		Coin,
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
	sf::Font& getFont();
	const sf::Texture& texture() const { return m_textures[1]; } // temporary
	Resources::Object getResourceType(ObjectType type);	// Mapping from ObjectType to Resources::Object
	AnimationData& animationData(Object object) { return m_data[object]; } // temporary

private:
	Resources();
	std::vector<sf::Texture> m_textures;	//to store all game textures
	std::vector<AnimationData> m_data;
	sf::Font m_font; // vector if we need more
};
