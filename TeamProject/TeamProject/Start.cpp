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
		case 1: printf("���ӽ���\n");
			game_start();
			break;
		case 2: printf("���ӹ��\n");
			break;
		case 3: printf("����\n");
			return;
		default: printf("�ٽ� �Է����ּ���\n");
			break;
		}
		printf("����Ϸ��� �ƹ�Ű���Է�\n");
		getch();
	}

}

void game_start()
{
	draw_map();
}