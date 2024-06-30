#pragma once
#include "Resources.h"

class InfoBar
{
public:
	InfoBar();
	virtual ~InfoBar() = default;
	void draw(sf::RenderTarget& window, const std::vector<int>& gameData);

private:
	void updateScore(const int score);
	void setData();
	std::vector<sf::Sprite> m_sprites;
	sf::Text m_score;
};