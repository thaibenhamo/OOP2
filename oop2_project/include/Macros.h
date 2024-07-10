#pragma once 
#include <string>
#include <SFML/Graphics.hpp>
#include <chrono>

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

enum AnimationState
{
	Stay,
	Move,
	Jump,
	Land,
	Shoot,
	Hit
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
	MenuBackground,
	LevelsMenuBackground,
	HelpMenuBackground,
	ScoresMenuBackground,
	CloudsBackground,
	WinBackground,
	LoseBackground,
	Count
};

enum ButtonType
{
	PlayButton = BackgroundType::Count,
	HelpButton,
	EndButton,
	BackButton,
	ScoresButton,
	LevelLockButton,
	Level1Button,
	Level2Button,
	Level3Button,
	Level4Button,
	CountButton
};

enum MusicType
{
	GameMusic,
	MenuMusic
};

enum SoundType
{
	ArrowHitEnemy,
	ArrowHitWall,
	CollectCoin,
	CollectGift,
	EnemyHitPlayer,
	PlayerDeath,
	PlayerJump,
	PlayerShoot
};

const int NUM_OF_TEXTURES = 33, NUM_OF_FONTS = 1;
const int DEFAULT_ROWS = 12, DEFAULT_COLS = 22;
const int FPS = 60;
const int PLAYER_STAY_PICS = 4, PLAYER_MOVE_PICS = 7, PLAYER_JUMP_PICS = 2, PLAYER_LAND_PICS = 2, 
		  PLAYER_SHOOT_PICS = 7, PLAYER_HIT_PICS = 1, PLAYER_OFFSET = 75;
const int BASIC_ENEMY_MOVE_PICS = 9;
const int FLYING_ENEMY_MOVE_PICS = 4;
const int MIN_SPACE = 6, START_LIVES = 3, ADD_POINTS = 50;
const int OFFSET_X_FOR_ARROW = -20, OFFSET_Y_FOR_ARROW = 10;
const int DIF_PLAYER_ARROW = 30;
const int TOP_WALL = 30;
const int NUM_OF_GIFTS = 3;
const int NUM_OF_MENU_BUTTONS = 3, NUM_OF_LEVELS = 4;
const int BUTTON_MENU_Y_LOC = 555, MIDDLE_SPCAE_BUTTON_MENU_Y = 100, OFFSET_BUTTON_MENU_Y = 40;
const int NUM_OF_SOUNDS = 8;
const int NUM_OF_MUSIC_TYPES = 2;
const unsigned int FONT_SIZE = 12;
const float MENU_SONG_VOLUME = 35.f, GAME_SONG_VOLUME = 50.f;
const float SCREEN_X_SIZE = 1650.f, SCREEN_Y_SIZE = 900.f;
const float OBJECTSIZE_X = 75.f, OBJECTSIZE_Y = 75.f;
const float CHASE_RADIUS = 500.0f;
const float FLICKERING_DURATION = 2.0f, MIN_STATIC_LIFE_DURATION = 10.0f;
const float MAX_STATIC_LIFE_DURATION = 10.0f, GIFT_DURATION = 10.0f;
const float TIME_FOR_CREATE_ARROW = 0.5f;
const float SPEED = 260.0f, ADD_SPEED = 150.0f;
const float ARROW_SPEED = SPEED * 3.5f;
const float BASIC_ENEMY_SPEED = 170.f;
const float PLAYER_HIGHT = 75.f;

const std::string LEVEL_NAME = "Level", FILE_EXTENSION = ".txt";

const sf::Vector2i PLAYER_SIZE = { 75, 75 }, PLAYER_INIT_SPACE = { 0, 0 }, PLAYER_MIDDLE_SPACE = { 0, 0 };
const sf::Vector2i BASIC_ENEMY_SIZE = { 75,63 }, BASIC_ENEMY_INIT_SPACE = { 0,450 };
const sf::Vector2i FLYING_ENEMY_SIZE = { 75,75 }, FLYING_ENEMY_INIT_SPACE = { 0,513 };
const sf::Vector2f SCALE_TO_THE_LEFT = { -1, 1 }, SCALE_TO_THE_RIGHT = { 1, 1 };

const sf::Color PINK = { 221, 79, 154, 255 };


const auto AnimationTime = sf::seconds(0.2f);
const float JUMPING_DURATION = 0.7f;


