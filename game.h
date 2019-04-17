#pragma once

#include "snake.h"
#include "food.h"

const int N = 20;
const int M = 20;

struct Game {

	bool isGameOn;
};

void drawField(char field[20][20]);

void initField(char field[20][20], Snake* snakeSt);

void execGame(bool* isGameOn, char field[20][20], Snake* snakeSt, Food* food);
