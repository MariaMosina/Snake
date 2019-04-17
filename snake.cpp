
#include "game.h"
#include "snake.h"
#include "food.h"
#include <windows.h>
#include <conio.h>
#include <iostream>



void initSnake( Snake* snakeSt)
{
 	*snakeSt = { 2, {5, 3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0}, { 3, 3, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0 },  Snake::RIGHT};
}

void setSnake(char field[20][20], Snake* snakeSt)
{
	switch (snakeSt->dir)
	{
	case Snake::LEFT:
		field[snakeSt->snY[0]][snakeSt->snX[0]] = '<';
		break;
	case Snake::RIGHT:
		field[snakeSt->snY[0]][snakeSt->snX[0]] = '>';
		break;
	case Snake::UP:
		field[snakeSt->snY[0]][snakeSt->snX[0]] = '^';
		break;
	case Snake::DOWN:
		field[snakeSt->snY[0]][snakeSt->snX[0]] = 'v';
		break;
	}
	for (int i = 1; i < snakeSt->size; i++)
	{
		field[snakeSt->snY[i]][snakeSt->snX[i]] = '@';
	}
}



void clearSnake(char field[20][20], Snake* snakeSt)
{
	for (int i = 0; i < snakeSt->size; i++)
	{
		field[snakeSt->snY[i]][snakeSt->snX[i]] = ' ';
	}
}

bool deadSnake(Snake* snakeSt)
{
	bool biteSnake = 0;
	for (int  i = 1; i < snakeSt->size; i++)
	{
		if ((snakeSt->snX[0] == snakeSt->snX[i+1]) && 
			(snakeSt->snY[0] == snakeSt->snY[i+1]))
		{
			biteSnake = 1;
			//break;
		}
		//else continue;
	}
	return biteSnake;
}

void updateSnake(char field[20][20], Snake* snakeSt)
{
	
	for (int i = snakeSt->size - 1; i > 0; i--)
	{
		if (((snakeSt->snX[i] == 18) && (snakeSt->dir == Snake::RIGHT)) ||
			((snakeSt->snX[i] == 1) && (snakeSt->dir == Snake::LEFT)) ||
			((snakeSt->snY[i] == 18) && (snakeSt->dir == Snake::DOWN)) ||
			((snakeSt->snY[i] == 1) && (snakeSt->dir == Snake::UP)))
		{
			switch (snakeSt->dir)
			{
			case Snake::LEFT:
				snakeSt->snX[i] = 18;
				break;
			case Snake::RIGHT:
				snakeSt->snX[i] = 1;
				break;
			case Snake::UP:
				snakeSt->snY[i] = 18;
				break;
			case Snake::DOWN:
				snakeSt->snY[i] = 1;
				break;
			}
		}
		else
		{
			snakeSt->snX[i] = snakeSt->snX[i - 1];
			snakeSt->snY[i] = snakeSt->snY[i - 1];
		}
	}

	if (((snakeSt->snX[0] == 18) && (snakeSt->dir == Snake::RIGHT)) ||
		((snakeSt->snX[0] == 1) && (snakeSt->dir == Snake::LEFT)) ||
		((snakeSt->snY[0] == 18) && (snakeSt->dir == Snake::DOWN)) ||
		((snakeSt->snY[0] == 1) && (snakeSt->dir == Snake::UP)))
	{
		switch (snakeSt->dir)
		{
		case Snake::LEFT:
			snakeSt->snX[0] = 18;
			break;
		case Snake::RIGHT:
			snakeSt->snX[0] = 1;
			break;
		case Snake::UP:
			snakeSt->snY[0] = 18;
			break;
		case Snake::DOWN:
			snakeSt->snY[0] = 1;
			break;
		}
	}
	else
	{
		switch (snakeSt->dir)
		{
		case Snake::LEFT:
			snakeSt->snX[0]--;
			break;
		case Snake::RIGHT:
			snakeSt->snX[0]++;
			break;
		case Snake::UP:
			snakeSt->snY[0]--;
			break;
		case Snake::DOWN:
			snakeSt->snY[0]++;
			break;
		}

	}
		Sleep(5);
	}
void animateSnake(char field[20][20], Snake* snakeSt, Food* food)
{
	clearSnake(field, snakeSt);
	if ((snakeSt->snX[0] == food->fX) && (snakeSt->snY[0] == food->fY))
	{
		food->isFoodExists = 0;
		snakeSt->size++;
	}
	updateSnake(field, snakeSt);
	setSnake(field, snakeSt);
}

void nextStep( char field[20][20], bool* isGameOn, Snake* snakeSt, Food* food)
{
	if (food->isFoodExists == 0)
	{
		setFood(field, food);
	}
	
	animateSnake(field, snakeSt, food);
	drawField(field);
	bool bite = deadSnake(snakeSt);
	if (bite == 1)
	{
		*isGameOn = 0;
		std::cout << "You bite your tail!\n";
	}
}