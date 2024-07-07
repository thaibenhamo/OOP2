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
	m_sprites[0].setPosition(sf::Vector2f(SCREEN_X_SIZE - 170.f , SCREEN_Y_SIZE - 100.f));

	m_sprites[1].setTexture(Resources::instance().get(Resources::ScoreDisplay));
	m_sprites[1].setPosition(sf::Vector2f(SCREEN_X_SIZE - 190.f, SCREEN_Y_SIZE - 60.f));

	m_sprites[2].setTexture(Resources::instance().get(Resources::Heart3));
	m_sprites[2].setPosition(sf::Vector2f(SCREEN_X_SIZE - 165.f, SCREEN_Y_SIZE - 94.f));

	sf::FloatRect spriteBounds = m_sprites[Score].getGlobalBounds();

	m_score.setFont(Resources::instance().getFont());
	m_score.setCharacterSize(FONT_SIZE);
	m_score.setFillColor(PINK);
	m_score.setPosition(spriteBounds.left + spriteBounds.width - FONT_SIZE * 5,
						spriteBounds.top + ((spriteBounds.height - FONT_SIZE) / 2.f));
	
}
void InfoBar::draw(sf::RenderTarget& window, const std::vector<int>& gameData)
{
	update(gameData);

	for(int spriteNum = 0; spriteNum < 3; spriteNum++)
		window.draw(m_sprites[spriteNum]);
	
	window.draw(m_score);
}

void InfoBar::update(const std::vector<int>& gameData)
{
	m_score.setString(std::to_string(gameData[Score]));

	if(gameData[Lives] == 1)
		m_sprites[2].setTexture(Resources::instance().get(Resources::Heart1));
	else if(gameData[Lives] == 2)
		m_sprites[2].setTexture(Resources::instance().get(Resources::Heart2));
	else if (gameData[Lives] >= 3)
		m_sprites[2].setTexture(Resources::instance().get(Resources::Heart3));
}

