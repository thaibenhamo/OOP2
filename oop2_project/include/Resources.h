#pragma once
#include "FileError.h"
#include <vector>
#include "Macros.h"
#include "AnimationData.h"
#include "Clock.h"
#include <SFML/Audio.hpp>

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

	const sf::Texture& get(const Object object) const;
	const sf::Texture& get(const BackgroundType type) const;
	const sf::Texture& texture() const { return m_textures[18]; }
	sf::Texture& get(const ButtonType buttonType);
	const sf::Font& getFont() const;
	Resources::Object getResourceType(ObjectType type);	// Mapping from ObjectType to Resources::Object
	AnimationData& animationData(Object object) { return m_data[object]; } 
	void playMusic(const MusicType type);
	void playSound(const SoundType type);

private:
	Resources();
	std::vector<sf::Texture> m_textures;	//to store all game textures
	std::vector<sf::Music> m_music;
	std::vector<sf::SoundBuffer> m_buffers;	//to store game sounds
	std::vector<AnimationData> m_data;
	sf::Font m_font; 
	sf::Sound m_sound;
};
