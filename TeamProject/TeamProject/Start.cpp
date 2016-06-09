#include "start.h"

void Go()
{
	int key = 0;
	int i = 0;
	while (key = selectMenu())
	{
		switch (key)
		{
		case 1: printf("���ӽ���\n");
			gameStart();
			break;
		case 2: printf("���ӹ��\n");
			howPlay();
			break;
		case 3:
			system("cls");
			showRanking();
			system("pause>null");
			break;
		case 4:
			system("cls");
			drawChar(10, 10, "bye bye");
			system("pause>null");
			return;
		default: printf("�ٽ� �Է����ּ���\n");
			break;
		}
	}
}

POS snake[MAX], item, item2;

void gameStart()
{

	int n = 0, score = 0, dir = -1, len = 5, count = 0,count2=0;
	int speed = 150;

	srand(time(NULL));

	drawMap();
	firstSnake(snake, len);

	//���̻Ѹ���
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;


	drawChar(1, 22, "Score : ");
	getchar();

	while (1)
	{
		//�浹 üũ
		if (checkSnake(snake, len) == 0)
		{
			break;
		}

		//���� ������ ���̻Ѹ��� ����+1
		if (snake[0].x == item.x && snake[0].y == item.y)
		{
			resetItem(len);
			score += 10;
			drawChar(1, 22, "Score : ");
			printf("%d", score);

			if (len < MAX)
			{
				snake[len] = snake[len - 1];
				len++;
				count++;

				if (count % 2 == 0)
				{
					speed = speed - 18;
					count2++;
				}

				if (count % 3 == 0)
				{
					resetItem2(len);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					drawChar(item2.x, item2.y, "��");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}

			}

		}
			if ((snake[0].x == item2.x) && (snake[0].y == item2.y))
			{
				speed = speed + 50;
				Sleep(speed);
			}	

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		drawChar(item.x, item.y, "��");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		moveSnake(snake, len);
		Sleep(speed);
	}



	system("cls");
	ranking(score);
	system("pause");
}


void resetItem(int len)
{
	int food_crush = 0, r = 0, i;
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;
	for (i = 0; i < len; i++)
	{
		if ((snake[i].x == item.x) && (snake[i].y == item.y))
		{
			food_crush = 1;
			r++;
			break;
		}
	}
	if (food_crush == 1)
	{
		srand((unsigned)time(NULL) + r);
		item.x = rand() % 28 + 1;
		item.y = rand() % 18 + 1;
	}
}

void resetItem2(int len)
{
	int food_crush = 0, r = 0, i;
	item2.x = rand() % 28 + 1;
	item2.y = rand() % 18 + 1;
	for (i = 0; i < len; i++)
	{
		if ((snake[i].x == item2.x) && (snake[i].y == item2.y))
		{
			food_crush = 1;
			r++;
			break;
		}

		else if ((item.x == item2.x) && (item.y == item2.y))
		{
			food_crush = 1;
			r++;
			break;
		}
	}
	if (food_crush == 1)
	{
		srand((unsigned)time(NULL) + r);
		item2.x = rand() % 28 + 1;
		item2.y = rand() % 18 + 1;
	}
}