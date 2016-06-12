#include "start.h"

POS snake[MAX], item, item2;

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
	//�� ���� �ʱ�ȭ
	int n = 0, score = 0, dir = -1, len = 5, count = 0,count2=0;
	int speed = 150;

	srand(time(NULL));

    //���� �׸���, ���� ó����ġ ����
	drawMap();
	firstSnake(snake, len);

	//���� ��ǥ ����
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

		//���� ������ ������ǥ �缳�� �첿��+1
		if (snake[0].x == item.x && snake[0].y == item.y)
		{
			//��ǥ ����, ���� ����
			resetItem(len);
			score += 10;
			drawChar(1, 22, "Score : ");
			printf("%d", score);

			//�������̰� �ִ뺸�� ������
			if (len < MAX)
			{
				snake[len] = snake[len - 1];
				len++;
				count++;

				//�ӵ� ����
				if (count % 2 == 0)
				{
					speed = speed - 8;
				}

			}
			
		}
	
		//�� ����, ���� ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		drawChar(item.x, item.y, "��");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		//�� �̵�����
		moveSnake(snake, len);

		//�ӵ� ����
		Sleep(speed);
	}

	system("cls");
	
	// �̸��Է¹ް� ���� ����, ��ŷ ���
	ranking(score);
	system("pause");
}


void resetItem(int len)
{
	int food_crush = 0, r = 0, i;

	//������ ��ǥ ����
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;

	for (i = 0; i < len; i++)
	{
		//����ǥ�� ������ ��ǥ�� �浹�ϸ� crush=1
		if ((snake[i].x == item.x) && (snake[i].y == item.y))
		{
			food_crush = 1;
			r++;
			break;
		}
	}
	if (food_crush == 1)
	{
		//��ǥ �缳��
		srand((unsigned)time(NULL) + r);
		item.x = rand() % 28 + 1;
		item.y = rand() % 18 + 1;
	}
}