#include "game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "snake.h"
#include "food.h"



void drawField(char field[20][20])
{
	system("cls");
	char* f = &field[0][0];
	for (int  i = 0; i < 20; i++)
	{
		for (int i = 0; i < 20; i++)
		{
			std::cout << *f;
			f++;
		}
		std::cout << '\n';
	}
}

void initField(char field[20][20],  Snake* snakeSt)
{
	initSnake(snakeSt);
	setSnake(field, snakeSt);
	char* p = &field[0][0];
	for (int  i = 0; i < 20; i++, p++)
	{
		*p = '#';
	}
	for (int i = 0; i < 20 * (20 - 2); i++, p++)
	{
		if (i % 20 == 0)
		{ 
			*(p - 1) = '#';
			*p = '#';
		}
		else
		{
			*p = ' ';
		}
	}
	for (int i = 0; i < 20; i++, p++)
	{
		*(p - 1) = '#';
		*p = '#';
	}
	
}

void execGame(bool* isGameOn, char field[20][20], Snake* snakeSt, Food* food)
{
	initField(field, snakeSt);
	*isGameOn = 1;
  	while (*isGameOn == 1)
	{
		if (!_kbhit())
			continue;
		else
		{
			char ch = _getch();		
			switch (ch)
			{
			case 75:				//код клавиши «стрелка влево»
				if (!(snakeSt->snX[0] > snakeSt->snX[1]))			
					snakeSt->dir = Snake::Direction::LEFT;
				break;
			case 77:				//код клавиши «стрелка вправо»
				if (!(snakeSt->snX[0] < snakeSt->snX[1]))
					snakeSt->dir = Snake::Direction::RIGHT;
				break;
			case 72:				//код клавиши «стрелка вверх»
				if (!(snakeSt->snY[0] > snakeSt->snY[1]))
					snakeSt->dir = Snake::Direction::UP;
				break;
			case 80:				//код клавиши «стрелка вниз»
				if (!(snakeSt->snY[0] < snakeSt->snY[1]))
					snakeSt->dir = Snake::Direction::DOWN;
				break;
			case 27:				//код клавиши escape
				*isGameOn = 0;					
				break;
			}
		}
		nextStep(field, isGameOn, snakeSt, food);
	}
}