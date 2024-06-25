#pragma once 
#include <string>
#include <SFML/Graphics.hpp>
#include <chrono>

enum class ObjectType
{
	PlayerChar = 'P',
	WallChar = '#',
	RandomEnemyChar = '&',
	SpaceChar = ' '
};

enum BackgroundType
{
	Background1 = 0,
	Count
};

enum MusicType
{

};

enum class SoundType
{

};

const int NUM_OF_TEXTURES = 4;
const std::string LEVEL_NAME = "Board", FILE_EXTENSION = ".txt";
const int DEFAULT_ROWS = 12;
const int DEFAULT_COLS = 24;
const float SCREEN_X_SIZE = 1920.f, SCREEN_Y_SIZE = 1050.f;
const int FPS = 60;
const float OBJECTSIZE_X = 75.f, OBJECTSIZE_Y = 75.f;
const int PLAYER_STAY_PICS = 4, PLAYER_MOVE_PICS = 7, PLAYER_UP_PICS = 2, PLAYER_DOWN_PICS = 2, PLAYER_OFFSET = 75;
const sf::Vector2i PLAYER_SIZE = { 75, 75 }, PLAYER_INIT_SPACE = { 0, 0 }, PLAYER_MIDDLE_SPACE = { 0, 0 };
const auto AnimationTime = sf::seconds(0.2f);
const sf::Vector2f SCALE_TO_THE_LEFT = { -1, 1 }, SCALE_TO_THE_RIGHT = { 1, 1 };
constexpr auto JUMPING_DURATION = std::chrono::milliseconds(500);
const float SPEED = 260.0f;
