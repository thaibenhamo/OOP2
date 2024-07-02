#pragma once 
#include <string>
#include <SFML/Graphics.hpp>
#include <chrono>

enum AnimationState
{
	Stay,
	Move,
	Jump,
	Land,
	Shoot
};
enum class ObjectType
{
	PlayerChar = 'P',
	WallChar = '#',
	CoinChar = '$',
	ArrowChar = '>',
	GiftChar = 'G',
	RandomEnemyChar = '&',
	FlyingEnemyChar = '*',
	SpaceChar = ' '
};

enum GameData
{
	Lives,
	Score,
	CountGameData
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

const int NUM_OF_TEXTURES = 15;
const int NUM_OF_FONTS = 1;
const float FONT_SIZE = 12.f;
const sf::Color PINK = { 221, 79, 154, 255 };
const std::string LEVEL_NAME = "Board", FILE_EXTENSION = ".txt";
const int DEFAULT_ROWS = 12;
const int DEFAULT_COLS = 24;
const float SCREEN_X_SIZE = 1920.f, SCREEN_Y_SIZE = 1050.f;
const int FPS = 60;
const float OBJECTSIZE_X = 75.f, OBJECTSIZE_Y = 75.f;
const int PLAYER_STAY_PICS = 4, PLAYER_MOVE_PICS = 7, PLAYER_JUMP_PICS = 2, PLAYER_LAND_PICS = 2, PLAYER_SHOOT_PICS = 7,
		  PLAYER_OFFSET = 75;
const sf::Vector2i PLAYER_SIZE = { 75, 75 }, PLAYER_INIT_SPACE = { 0, 0 }, PLAYER_MIDDLE_SPACE = { 0, 0 };
const auto AnimationTime = sf::seconds(0.2f);
const sf::Vector2f SCALE_TO_THE_LEFT = { -1, 1 }, SCALE_TO_THE_RIGHT = { 1, 1 };
constexpr auto JUMPING_DURATION = std::chrono::milliseconds(500);
const float SPEED = 260.0f;
const int PLAYER_HIGHT = 75, MIN_SPACE = 6, START_LIVES = 3, ADD_POINTS = 50;
const float BASIC_ENEMY_SPEED = 170.f;
const int BASIC_ENEMY_MOVE_PICS = 9;
const int FLYING_ENEMY_MOVE_PICS = 4;
const sf::Vector2i BASIC_ENEMY_SIZE = { 75,63 }, BASIC_ENEMY_INIT_SPACE = { 0,450 };
const sf::Vector2i FLYING_ENEMY_SIZE = { 75,75 }, FLYING_ENEMY_INIT_SPACE = { 0,513 };
const float CHASE_RADIUS = 500.0f;
const float FLICKERING_DURATION = 2.0f;
const float BULLET_SPEED = SPEED * 3.5f;
const float TIME_FOR_CREATE_ARROW = 1.2f;
const int OFFSET_X_FOR_BULLET = 50, OFFSET_Y_FOR_BULLET = 10;
const int DIF_PLAYER_ARROW = 30, TOP_WALL = 30;
