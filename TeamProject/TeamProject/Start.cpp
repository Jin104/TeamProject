#include "feed.h"
#include "snake.h"
#include "map.h"
#include "start.h"
#include <stdio.h>
#include <conio.h>

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
	draw_map();
}