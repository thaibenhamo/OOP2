#include "Resources.h"

namespace
{
	int num_of_pics;

	void readData(AnimationData& animation, sf::Vector2i& currentStart, sf::Vector2i& initSpace,
		          sf::Vector2i& middleSpace, Direction state, sf::Vector2i& size, int pics, 
				  int anim_off, int offset) {

		auto nextStart = [&]()
			{
				currentStart += middleSpace;
				currentStart.x += size.x;
				return currentStart;
			};

		currentStart = { initSpace.x, initSpace.y + anim_off * offset };
		animation.m_data[state].emplace_back(currentStart, size);

		for (num_of_pics = 1; num_of_pics < pics; num_of_pics++)
			animation.m_data[state].emplace_back(nextStart(), size);
	}

	AnimationData playerData()
	{
		auto size = PLAYER_SIZE;
		auto initSpace = PLAYER_INIT_SPACE;
		auto middleSpace = PLAYER_MIDDLE_SPACE;

		auto player = AnimationData{};
		auto currentStart = initSpace;

		// stay
		readData(player, currentStart, initSpace, middleSpace, Direction::Stay, size, PLAYER_STAY_PICS,
				 PLAYER_OFFSET, 0);
		readData(player, currentStart, initSpace, middleSpace, Direction::Left, size, PLAYER_MOVE_PICS,
			PLAYER_OFFSET, 1);
		readData(player, currentStart, initSpace, middleSpace, Direction::Right, size, PLAYER_MOVE_PICS,
			PLAYER_OFFSET, 1);
		readData(player, currentStart, initSpace, middleSpace, Direction::Up, size, PLAYER_UP_PICS,
			PLAYER_OFFSET, 2);
		readData(player, currentStart, initSpace, middleSpace, Direction::Down, size, PLAYER_DOWN_PICS,
			PLAYER_OFFSET, 3);
		return player;
	}
}

Resources::Resources() : m_data(Max) {

	m_textures.resize(NUM_OF_TEXTURES);

	std::ifstream file = std::ifstream("FilesList.txt");	//open level file

	if (file) {

		auto line = std::string();			// to reads lines from the file

		// read textures names from file
		for (int i = 0; i < NUM_OF_TEXTURES; i++) {

			if (!std::getline(file, line))
				throw std::runtime_error("Can't read from file");

			m_textures[i].loadFromFile(line);	
		}
	}
	else
		throw std::runtime_error("Can't load file1");

	// set animation
	m_data[Player] = playerData();
}

sf::Texture& Resources::get(const Object object)
{
	return m_textures[object];
}

Resources::Object Resources::getResourceType(ObjectType type) 
{
	switch (type) {
	case ObjectType::PlayerChar:
		return Player;
	case ObjectType::WallChar:
		return Wall; 
	case ObjectType::RandomEnemyChar:
		return RandomEnemy;
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
