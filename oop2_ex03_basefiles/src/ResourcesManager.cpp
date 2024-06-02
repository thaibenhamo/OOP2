#include <iostream>
#include "ResourcesManager.h"

ResourcesManager::ResourcesManager()
{
    if (!m_font.loadFromFile("FONT.ttf"))
        exit(EXIT_FAILURE);

    loadTexture("background", "background.png");
    loadTexture("menu", "menu.png");
    loadTexture("button1", "button1.png");
};

ResourcesManager& ResourcesManager::instance()
{
    static ResourcesManager inst;
    return inst;
}

void ResourcesManager::loadTexture(const std::string& name, const std::string& filename)
{
    sf::Texture texture;

    if (!texture.loadFromFile(filename)) 
    {
        exit(EXIT_FAILURE);
    }
    m_SticksTextures[name] = texture;
}

const sf::Texture* ResourcesManager::getTexture(const std::string& name) const
{
    return &m_SticksTextures.at(name); 
}

const sf::Font* ResourcesManager::getFont() const
{
    return &m_font; 
}