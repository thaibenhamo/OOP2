#pragma once

#include <SFML/Graphics.hpp>

enum BoardOption
{
	Hint,
	Save,
	Quit
};

enum MenuOption
{
	startGame,
	Load,
	Exit
};

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

const double PI = 3.14159265358979323846;

const int MAX_STICK_LENGTH = 280;
const int MIN_STICK_LENGTH = 50;

const int MAX_START_X = 910;
const int MIN_START_X = 520;

const int MAX_START_Y = 520;
const int MIN_START_Y = 280;

const int MAX_ANGLE = 360;

const int MAX_COLOR_INDEX = 5;

