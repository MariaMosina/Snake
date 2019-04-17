#pragma once

#include "game.h"
#include "food.h"

//const int L = 50;
//const int N = 20;
//const int M = 20;


struct Snake {
	int size;
	int snX[50];
	int snY[50];
	enum Direction { LEFT, RIGHT, UP, DOWN };
	Direction dir;
};

void initSnake(Snake* snakeSt);

void setSnake(char field[20][20], Snake* snakeSt);

void clearSnake(char field[20][20], Snake* snakeSt);

bool deadSnake(Snake* snakeSt);

void updateSnake(char field[20][20], Snake* snakeSt);

void animateSnake(char field[20][20], Snake* snakeSt, Food* food);

void nextStep(char field[20][20], bool* isGameOn, Snake* snakeSt,  Food* food);