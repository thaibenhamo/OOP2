#pragma once 
#include <string>


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
