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

void gameStart()
{
	POS snake[MAX],item;
	int n = 0, score = 0,dir = -1, len = 5, count=0;
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
		int food_crush = 0, r = 0, i;
		
		srand((unsigned)time(NULL) + r);
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
			if (food_crush == 1)
			{
				continue;
				
			}
			drawChar(item.x, item.y, "��");
		}
		
	}



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
			int food_crush = 0,r = 0, i;
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
					speed = speed - 8;
				}
			}
		}
		
		setColorRed();	
		drawChar(item.x, item.y, "��");
		setColorWhite();
		moveSnake(snake, len);
		Sleep(speed);
	}
	system("cls");
	ranking(score);
	system("pause");
}
