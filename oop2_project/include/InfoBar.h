#pragma once
#include "Resources.h"

class Infobar
{
public:
	Infobar();
	virtual ~Infobar() = default;

	const int getLevelNum() const;

private:
	void updateScore(const int score);
	void setData();
	std::vector<sf::Sprite> m_sprites;
	sf::Text m_score;
};