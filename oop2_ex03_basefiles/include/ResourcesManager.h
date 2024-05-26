#include <SFML/Graphics.hpp>
#include <unordered_map>

class ResourcesManager
{
public:
	static ResourcesManager& instance();
	const sf::Texture *getTexture(const std::string& name) const;

private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager&) = delete;
	void loadTexture(const std::string& name, const std::string& filename);
	//sf::Font m_font;
	std::unordered_map<std::string,sf::Texture> m_SticksTextures;
};