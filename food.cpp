
#include "game.h"
#include "food.h"
#include <iostream>
#include <ctime>


void setFood(char field[20][20], Food* food)
{
	srand(time(0));
	food->fX = 1 + rand() % 18;
	food->fY = 1 + rand() % 18;
	char& f = field[0][0];
	field[food->fY][food->fX] = '+';
	food->isFoodExists = 1;
}