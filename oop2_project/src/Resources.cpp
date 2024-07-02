#include "Resources.h"

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

Resources::Resources() : m_data(Max) 
{
	m_textures.resize(NUM_OF_TEXTURES);

	std::ifstream file = std::ifstream("FilesList.txt");	//open level file

	if (file) 
	{
		auto line = std::string();			// to reads lines from the file

		// read textures names from file
		for (int i = 0; i < NUM_OF_TEXTURES; i++) {

			if (!std::getline(file, line))
				throw std::runtime_error("Can't read from file");

			m_textures[i].loadFromFile(line);
		}

		// read font names from file
		for (int i = 0; i < NUM_OF_FONTS; i++) {
			if (!std::getline(file, line))
				throw std::runtime_error("Can't read from file");
			m_font.loadFromFile(line);
		}
	}
	else
		throw std::runtime_error("Can't load file1");

	// set animation
	m_data[Player] = playerData();
	m_data[RandomEnemy] = randomEnemyData();
	m_data[FlyingEnemy] = flyingEnemyData();
}

sf::Texture& Resources::get(const Object object)
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
		return SpeedGift;
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

sf::Texture& Resources::get(const BackgroundType backgroundtype)
{
	return m_textures[backgroundtype];
}

sf::Font& Resources::getFont()
{
	return m_font;
}
