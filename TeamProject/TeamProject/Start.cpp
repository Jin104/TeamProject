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
	POS snake[MAX],item;
	int i, n = 0, dir = -1, len = 5;
	int speed = 150;

	srand(time(NULL));

	draw_map();
	first_snake(snake, len);

	//���̻Ѹ���
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;
	//make_feed(item);

	while (1)
	{
		//�浹 üũ
		if (check_snake(snake, len) == 0)
		{
			break;
		}

		//���� ������ ���̻Ѹ��� ����+1
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

		draw_char(item.x, item.y, "��");
		move_snake(snake, len);
		Sleep(speed);
	}
	
}

void how_play()
{

}