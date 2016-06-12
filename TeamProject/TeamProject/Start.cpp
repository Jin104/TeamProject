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
	//각 변수 초기화
	int n = 0, score = 0, dir = -1, len = 5, count = 0,count2=0;
	int speed = 150;

	srand(time(NULL));

    //맵을 그리고, 뱀의 처음위치 지정
	drawMap();
	firstSnake(snake, len);

	//먹이 좌표 지정
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;

	drawChar(1, 22, "Score : ");
	getchar();

	while (1)
	{
		//충돌 체크
		if (checkSnake(snake, len) == 0)
		{
			break;
		}

		//먹이 먹으면 먹이좌표 재설정 뱀꼬리+1
		if (snake[0].x == item.x && snake[0].y == item.y)
		{
			//좌표 설정, 점수 증가
			resetItem(len);
			score += 10;
			drawChar(1, 22, "Score : ");
			printf("%d", score);

			//꼬리길이가 최대보다 적으면
			if (len < MAX)
			{
				snake[len] = snake[len - 1];
				len++;
				count++;

				//속도 증가
				if (count % 2 == 0)
				{
					speed = speed - 8;
				}

			}
			
		}
	
		//색 설정, 먹이 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		drawChar(item.x, item.y, "♥");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		//뱀 이동구현
		moveSnake(snake, len);

		//속도 지정
		Sleep(speed);
	}

	system("cls");
	
	// 이름입력받고 점수 저장, 랭킹 기록
	ranking(score);
	system("pause");
}


void resetItem(int len)
{
	int food_crush = 0, r = 0, i;

	//아이템 좌표 설정
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;

	for (i = 0; i < len; i++)
	{
		//뱀좌표와 먹이의 좌표가 충돌하면 crush=1
		if ((snake[i].x == item.x) && (snake[i].y == item.y))
		{
			food_crush = 1;
			r++;
			break;
		}
	}
	if (food_crush == 1)
	{
		//좌표 재설정
		srand((unsigned)time(NULL) + r);
		item.x = rand() % 28 + 1;
		item.y = rand() % 18 + 1;
	}
}