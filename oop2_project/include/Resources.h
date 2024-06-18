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


class Resources {

public:
	enum Object
	{
		Player = BackgroundType::Count,
		Wall,
		RandomEnemy,
		Space
	};

	//Singleton, provides a centralized access point to these resources.
	static Resources& instance() {
		static auto resources = Resources(); 
		return resources;
	}

	//delete copy c-tor and operator=
	Resources(const Resources&) = delete;
	void operator=(const Resources&) = delete;

	//sf::Font& get();
	sf::Texture& get(const Object object);
	sf::Texture& get(const BackgroundType type);
	Resources::Object getResourceType(ObjectType type);	// Mapping from ObjectType to Resources::Object
	
private:
	Resources();
	std::vector<sf::Texture> m_textures;	//to store all game textures
	//std::vector<sf::SoundBuffer> m_buffers;	//to store game sounds
	//sf::Music m_musics[NUM_OF_MUSICS];		// sf::Music can not be used by std::vector
	//sf::Font m_font;						//to store game font
	//sf::Sound m_sound;
};
