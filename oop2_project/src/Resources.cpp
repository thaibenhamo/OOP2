#include "Resources.h"
#include <fstream>
#include "FileError.h"

namespace
{
	int num_of_pics;

	void readData(AnimationData& animation, sf::Vector2i& currentStart, sf::Vector2i& initSpace,
				  AnimationState state, sf::Vector2i& size, int pics, int offset)
	{
		auto nextStart = [&]()
			{
				currentStart.x += size.x;
				return currentStart;
			};

		currentStart = { initSpace.x, initSpace.y + size.x * offset };
		animation.m_data[state].emplace_back(currentStart, size);

		for (num_of_pics = 1; num_of_pics < pics; num_of_pics++)
			animation.m_data[state].emplace_back(nextStart(), size);
	}

	AnimationData playerData()
	{
		auto size = PLAYER_SIZE;
		auto initSpace = PLAYER_INIT_SPACE;

		auto player = AnimationData{};
		auto currentStart = initSpace;

		readData(player, currentStart, initSpace, AnimationState::Stay, size, PLAYER_STAY_PICS, 0);
		readData(player, currentStart, initSpace, AnimationState::Move, size, PLAYER_MOVE_PICS, 1);
		readData(player, currentStart, initSpace, AnimationState::Jump, size, PLAYER_JUMP_PICS, 2);
		readData(player, currentStart, initSpace, AnimationState::Land, size, PLAYER_LAND_PICS, 3);
		readData(player, currentStart, initSpace, AnimationState::Shoot, size, PLAYER_SHOOT_PICS, 4);
		readData(player, currentStart, initSpace, AnimationState::Hit, size, PLAYER_HIT_PICS, 5);
		return player;
	}
	AnimationData randomEnemyData()
	{
		auto size = BASIC_ENEMY_SIZE;
		auto initSpace = BASIC_ENEMY_INIT_SPACE;

		auto randomEnemy = AnimationData{};
		auto currentStart = initSpace;

		readData(randomEnemy, currentStart, initSpace, AnimationState::Move, size, BASIC_ENEMY_MOVE_PICS, 0);
		return  randomEnemy;
	}

	AnimationData flyingEnemyData()
	{
		auto size = FLYING_ENEMY_SIZE;
		auto initSpace = FLYING_ENEMY_INIT_SPACE;

		auto flyingEnemy = AnimationData{};
		auto currentStart = initSpace;

		readData(flyingEnemy, currentStart, initSpace, AnimationState::Move, size, FLYING_ENEMY_MOVE_PICS, 0);
		return  flyingEnemy;
	}
}

Resources::Resources() : m_data(Max), m_music(NUM_OF_MUSIC_TYPES), m_buffers(NUM_OF_SOUNDS)
{
	m_textures.resize(NUM_OF_TEXTURES);

	std::ifstream file = std::ifstream("FilesList.txt");	//open level file

	if (file) 
	{
		auto line = std::string();			// to reads lines from the file

		// read textures names from file
		for (int i = 0; i < NUM_OF_TEXTURES; i++) 
		{
			if (!std::getline(file, line))
			{
				throw std::runtime_error("Can't read from file");
			}		
			m_textures[i].loadFromFile(line);
		}

		// read font names from file
		for (int i = 0; i < NUM_OF_FONTS; i++) 
		{
			if (!std::getline(file, line))
			{
				throw std::runtime_error("Can't read from file");
			}		
			m_font.loadFromFile(line);
		}

		// read music names from file
		for (int i = 0; i < NUM_OF_MUSIC_TYPES; i++)
		{
			if (!std::getline(file, line))
			{
				throw std::runtime_error("Can't read from file");
			}
			m_music[i].openFromFile(line);
		}

		// read sounds names from file
		for (int i = 0; i < NUM_OF_SOUNDS; i++) 
		{
			if (!std::getline(file, line))
			{
				throw std::runtime_error("Can't read from file");
			}		
			m_buffers[i].loadFromFile(line);
		}
	}
	else
	{
		throw std::runtime_error("Can't load file");
	}
		
	// set volume
	m_music[MenuMusic].setVolume(MENU_SONG_VOLUME);
	m_music[GameMusic].setVolume(GAME_SONG_VOLUME);

	// set animation
	m_data[Player] = playerData();
	m_data[RandomEnemy] = randomEnemyData();
	m_data[FlyingEnemy] = flyingEnemyData();
}

const sf::Texture& Resources::get(const Object object) const
{
	return m_textures[object];
}

Resources::Object Resources::getResourceType(ObjectType type) 
{
	switch (type) 
	{
	case ObjectType::PlayerChar:
		return Player;
	case ObjectType::WallChar:
		return Wall; 
	case ObjectType::CoinChar:
		return Coin;
	case ObjectType::ArrowChar:
		return Arrow;
	case ObjectType::GiftChar:
		return BubbleGift;
	case ObjectType::RandomEnemyChar:
		return RandomEnemy;
	case ObjectType::FlyingEnemyChar:
		return FlyingEnemy;
	case ObjectType::SpaceChar:
		return Space;
		// Add cases for other ObjectType values
	default:
		throw std::runtime_error("Unknown ObjectType");
	}
}

const sf::Texture& Resources::get(const BackgroundType backgroundtype) const 
{
	return m_textures[backgroundtype];
}

const sf::Font& Resources::getFont() const 
{
	return m_font;
}

sf::Texture& Resources::get(const ButtonType buttonType)
{
	return m_textures[buttonType];
}

void Resources::playMusic(const MusicType type)
{
	switch (type)
	{
	case MusicType::MenuMusic:
		m_music[GameMusic].stop();
		m_music[MenuMusic].play();
		m_music[MenuMusic].setLoop(true);
		return;

	case MusicType::GameMusic:
		m_music[MenuMusic].stop();
		m_music[GameMusic].play();
		m_music[GameMusic].setLoop(true);
		return;
	}
	throw std::runtime_error("No music found");
}

void Resources::playSound(const SoundType type) 
{
	m_sound.setBuffer(m_buffers[type]);
	m_sound.play();	
}
