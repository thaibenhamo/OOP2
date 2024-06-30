#pragma once
#include "Infobar.h"

InfoBar::InfoBar() 
	: m_sprites(3)
{
	setData();
}

void InfoBar::setData()
{
	m_sprites[0].setTexture(Resources::instance().get(Resources::LivesDisplay));
	m_sprites[0].setPosition(sf::Vector2f(1750.f, 950.f));

	m_sprites[1].setTexture(Resources::instance().get(Resources::ScoreDisplay));
	m_sprites[1].setPosition(sf::Vector2f(1730.f, 990.f));

	m_sprites[2].setTexture(Resources::instance().get(Resources::Heart3));
	m_sprites[2].setPosition(sf::Vector2f(1755.f, 956.f));

	sf::FloatRect spriteBounds = m_sprites[Score].getGlobalBounds();
	m_score.setFont(Resources::instance().getFont());
	m_score.setCharacterSize(12);
	m_score.setFillColor(sf::Color(221, 79, 154, 255));
	m_score.setPosition(spriteBounds.left + spriteBounds.width - 12.f * 5,
						spriteBounds.top + ((spriteBounds.height - 12.f) / 2.f));
	
}
void InfoBar::draw(sf::RenderTarget& window, const std::vector<int>& gameData)
{
	updateScore(gameData[Score]);

	for(int spriteNum = 0; spriteNum < 2; spriteNum++)
		window.draw(m_sprites[spriteNum]);
	
	switch (gameData[Lives])
	{
	case 1:
		m_sprites[2].setTexture(Resources::instance().get(Resources::Heart1));
		break;
	case 2:
		m_sprites[2].setTexture(Resources::instance().get(Resources::Heart2));
		break;
	default:
		break;
	}
	window.draw(m_sprites[2]);
	window.draw(m_score);
}

void InfoBar::updateScore(const int score)
{
	m_score.setString(std::to_string(score));

}

