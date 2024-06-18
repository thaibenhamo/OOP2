#include "Resources.h"

Resources::Resources() {

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

//=========================================================
sf::Texture& Resources::get(const BackgroundType backgroundtype)
{
	return m_textures[backgroundtype];
}
