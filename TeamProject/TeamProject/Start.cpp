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
			case 1: printf("게임시작\n");
				gameStart();
				break;
			case 2: printf("게임방법\n");
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
			default: printf("다시 입력해주세요\n");
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

	//먹이뿌리기
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;

	drawChar(1, 21, "Score : ");
	getchar();
	while (1)
	{
		//충돌 체크
		if (checkSnake(snake, len) == 0)
		{
			break;
		}

		//먹이 먹으면 먹이뿌리고 길이+1
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
		drawChar(item.x, item.y, "♡");
		moveSnake(snake, len);
		Sleep(speed);
	}
	system("cls");
	printf("GameOver\n");
	ranking(score);
	system("pause");
}


//랭킹저장
void ranking(int score)
{
	printf("이름을 입력하세요\n");
	
	scanf("%s", name);
	printf("%s의 점수는 %d\n", name, score);
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

//랭킹출력
void showRanking()
{
	int i;
	//system("cls");
	printf("점수가 같을경우는 먼저플레이한사람이 등수가 높습니다.\n\n");
	for (i = 0; i < nameCount; i++)
	{
		printf("%d등 : %s  %2d점\n", i + 1, rankName[i], rankScore[i]);
	}

}