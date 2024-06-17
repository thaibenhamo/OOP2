#include "Resources.h"
#include "Macros.h"

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
	switch (object)
	{
	case Object::Player:
		return m_textures[0];
	}
	throw std::runtime_error("No Texture of that type");
}