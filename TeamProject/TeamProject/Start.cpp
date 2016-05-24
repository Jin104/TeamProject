#include "start.h"

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
			how_play();
			break;
		case 3:
			system("cls");
			draw_char(10, 10, "bye bye");
			system("pause>null");
			return;
		default: printf("�ٽ� �Է����ּ���\n");
			break;
		}
	}

}

void game_start()
{
	POS snake[MAX],item;
	int i, n = 0, score = 0,dir = -1, len = 5, count=0;
	int speed = 150;

	srand(time(NULL));

	draw_map();
	first_snake(snake, len);

	//���̻Ѹ���
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;
	//make_feed(item);
	draw_char(1, 21, "Score : ");
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

			score += 10;
			draw_char(1, 21, "Score : ");
			printf("%d", score);

			if (len < MAX)
			{
				snake[len] = snake[len - 1];
				len++;
				count++;
				if (count % 2 == 0)
				{
					speed = speed - 5;
				}
			}
		}
		draw_char(item.x, item.y, "��");
		move_snake(snake, len);
		Sleep(speed);
	}
	
}

void how_play()
{
	system("cls");
	draw_char(10, 9, "ESC �Ͻ�����");
	draw_char(10, 10, "����Ű�� ����Ͽ� ���� �����δ�.");
	draw_char(10, 11, "����(��)�� ������ ������ �ϳ��� �����Ѵ�.");
	draw_char(10, 12, "���̳� ���� ������ ���ӿ���");
	draw_char(25, 20, "�ڷΰ��� : �ƹ�Ű�� �������");
	system("pause>null");
	system("cls");
}