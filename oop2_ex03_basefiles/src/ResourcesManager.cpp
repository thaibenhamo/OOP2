#include <iostream>
#include "ResourcesManager.h"
#include "TextureLoadException.h"

ResourcesManager::ResourcesManager()
{
    try
    {
        loadTexture("stick1", "stick1.png");
    }
    catch (const TextureLoadException& e)
    {
        throw; // Rethrow exception to propagate it to the caller
    }
};

ResourcesManager& ResourcesManager::instance()
{
    static ResourcesManager inst;
    return inst;
}

void ResourcesManager::loadTexture(const std::string & name, const std::string & filename)
{
    sf::Texture texture;

    if (!texture.loadFromFile(filename)) 
    {
        throw TextureLoadException(filename);
        std::cerr << "Failed to load textures. Exiting program." << std::endl;
    }
    texture.setSmooth(true);
    m_SticksTextures[name] = texture;
    //std::cout << "Loaded texture: " << filename << std::endl;
}

const sf::Texture* ResourcesManager::getTexture(const std::string& name) const
{
    return &m_SticksTextures.at(name); // Throws std::out_of_range if texture not found
}