#include "start.h"

char name[50];
char rankName[50][50];
int rankScore[50];
int nameCount = 0;

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
	int i, n = 0, score = 0,dir = -1, len = 5, count=0;
	int speed = 150;

	srand(time(NULL));

	drawMap();
	firstSnake(snake, len);

	//���̻Ѹ���
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;

	drawChar(1, 21, "Score : ");
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
			
			item.x = rand() % 28 + 1;
			item.y = rand() % 18 + 1;

			score += 10;
			drawChar(1, 21, "Score : ");
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
		drawChar(item.x, item.y, "��");
		moveSnake(snake, len);
		Sleep(speed);
	}
	system("cls");
	printf("GameOver\n");
	ranking(score);
	system("pause");
}


//��ŷ����
void ranking(int score)
{
	printf("�̸��� �Է��ϼ���\n");
	
	scanf("%s", name);
	printf("%s�� ������ %d\n", name, score);
	nameCount++;

	int i,j, scoreTmp=0;
	char nameTmp[50];

	for (i = 0; i < 50; i++)
	{
		if (rankScore[i] < score)
		{
			scoreTmp = rankScore[i];
			for (j = 0; j < 50; j++)
			{
				nameTmp[j] = rankName[i][j];
			}
			rankScore[i] = score;
			for(j = 0; j < 50; j++)
			{
				rankName[i][j] = name[j];
			}
			score = scoreTmp;
			for (j = 0; j < 50; j++)
			{
				name[j] = nameTmp[j];
			}
		}
	}


}

//��ŷ���
void showRanking()
{
	int i;
	//system("cls");
	printf("������ �������� �����÷����ѻ���� ����� �����ϴ�.\n\n");
	for (i = 0; i < nameCount; i++)
	{
		printf("%d�� : %s  %2d��\n", i + 1, rankName[i], rankScore[i]);
	}

}