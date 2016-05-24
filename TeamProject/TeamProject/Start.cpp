#include "start.h"

void Go()
{
	int key = 0;
	while (key = select_menu())
	{
		switch (key)
		{
		case 1: printf("게임시작\n");
			game_start();
			break;
		case 2: printf("게임방법\n");
			how_play();
			break;
		case 3:
			system("cls");
			draw_char(10, 10, "bye bye");
			system("pause>null");
			return;
		default: printf("다시 입력해주세요\n");
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

	//먹이뿌리기
	item.x = rand() % 28 + 1;
	item.y = rand() % 18 + 1;
	//make_feed(item);
	draw_char(1, 21, "Score : ");
	while (1)
	{
		//충돌 체크
		if (check_snake(snake, len) == 0)
		{
			break;
		}

		//먹이 먹으면 먹이뿌리고 길이+1
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
		draw_char(item.x, item.y, "♡");
		move_snake(snake, len);
		Sleep(speed);
	}
	
}

void how_play()
{
	system("cls");
	draw_char(10, 9, "ESC 일시정지");
	draw_char(10, 10, "방향키를 사용하여 뱀을 움직인다.");
	draw_char(10, 11, "먹이(♡)를 먹으면 꼬리가 하나씩 증가한다.");
	draw_char(10, 12, "벽이나 몸에 박으면 게임오버");
	draw_char(25, 20, "뒤로가기 : 아무키나 누르면됨");
	system("pause>null");
	system("cls");
}