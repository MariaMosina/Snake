#pragma once

#include "game.h"
#include "snake.h"

struct Food {
	int fX;
	int fY;
	bool isFoodExists;
};

void setFood(char field[20][20], Food* food);