#include "feed.h"
#include "snake.h"
#include "map.h"
#include "start.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void Go()
{
	int key = 0;
	while (key = select_menu())
	{
		switch (key)
		{
		case 1: printf("게임시작\n");
			game_start();
			break;
		case 2: printf("게임방법\n");
			break;
		case 3: printf("종료\n");
			return;
		default: printf("다시 입력해주세요\n");
			break;
		}
		printf("계속하려면 아무키나입력\n");
		getch();
	}

}

void game_start()
{
	POS snake[MAX],item;
	int i, n = 0, dir = -1, len = 5;
	int speed = 150;

	srand(time(NULL));

	draw_map();
	first_snake(snake, len);

	//먹이뿌리기
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;
	//make_feed(item);

	while (1)
	{
		//충돌 체크
		if (check_snake(snake, len) == 0)
		{
			break;
		}

		//먹이 먹으면 먹이뿌리고 길이+1
		if (snake[0].x == item.x && snake[0].y == item.y)
		{
			
			item.x = rand() % 28 + 1;
			item.y = rand() % 18 + 1;

			if (len < MAX)
			{
				snake[len] = snake[len - 1];
				len++;
			}
		}

		draw_char(item.x, item.y, "♡");
		move_snake(snake, len);
		Sleep(speed);
	}
	
}

void how_play()
{

}