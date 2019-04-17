#include <iostream>
#include "game.h"
#include "snake.h"
#include "food.h"

//const int L = 50;
//const int M = 20;
//const int N = 20;


int main()
{
	char field[20][20];
	Food food = { 0,0,0 };
	Snake snakeSt = { 0 };
	bool isGameOn = 0;
	execGame(&isGameOn, field,  &snakeSt,  &food);

	system("pause");
	return 0;
}