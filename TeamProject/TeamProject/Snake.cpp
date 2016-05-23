#include "snake.h"
#include "map.h"
#include <stdio.h>
#include <conio.h>

void move_snake(POS* snake, int len)
{
	static int dir = -1;

	if (kbhit())
	{
		int key;
		do
		{
			key = getch();
		} while (key == 224); //����Ű�� Ư��Ű�� �ν� ex) LEFT �Է°� 224 75

		switch (key)
		{
			case 72 :  //��
				dir = 0;
				break;
			case 80 :  //��
				dir = 1;
				break;
			case 75 :  //��
				dir = 2;
				break;
			case 77 :  //��
				dir = 3;
				break;
			default:
				break;
		}
	}

	// �� ����
	if (dir != -1)
	{
		int i;
		draw_char(snake[len - 1].x, snake[len - 1].y, "  ");
		for (i = len - 1; i>0; i--) snake[i] = snake[i - 1];
		draw_char(snake[1].x, snake[1].y, "��");
	}

	// �� �Ӹ� 
	switch (dir)
	{
		case 0: 
			snake[0].y--; 
			break;
		case 1: 
			snake[0].y++; 
			break;
		case 2: 
			snake[0].x--; 
			break;
		case 3: 
			snake[0].x++; 
			break;
	}
	draw_char(snake[0].x, snake[0].y, "��");
}

int check_snake(POS* snake, int len)
{
	int i;

	//�Ӹ� ��
	if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == 34 || snake[0].y == 20)
	{
		return 0;
	}

	//�Ӹ� ����
	for (i = 1; i < len; i++)
	{
		if (snake[0].x == snake[i].x&&snake[0].y == snake[i].y)
		{
			return 0;
		}
	}

	return 1;
}

int first_snake(POS* snake, int len)
{
	int i;
	for (i = 0; i<len; i++)
	{
		snake[i].x = 15 + i;
		snake[i].y = 10;
		draw_char(snake[i].x, snake[i].y, "��");
	}
	return 1;
}