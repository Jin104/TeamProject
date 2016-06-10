#include "start.h"

void moveSnake(POS* snake, int len)
{
	static int dir = -1;

	//키보드 값 입력
	if (kbhit())
	{
		int key;
		do
		{
			key = getch();
		} while (key == 224); //방향키는 특수키로 인식 ex) LEFT 입력값 224 75

		switch (key)
		{
			case 72 :  //↑
				dir = 0;
				break;
			case 80 :  //↓
				dir = 1;
				break;
			case 75 :  //←
				dir = 2;
				break;
			case 77 :  //→
				dir = 3;
				break;
			case ESC :
				system("pause>null");
				break;
			default:
				break;
		}
	}

	// 뱀 몸통 이동
	if (dir != -1)
	{
		int i;

		drawChar(snake[len - 1].x, snake[len - 1].y, "  "); //몸통의 마지막을 지움

		for (i = len - 1; i > 0; i--)
		{
			snake[i] = snake[i - 1];	//몸통의 좌표를 한칸씩 옮김
		}
		
		drawChar(snake[1].x, snake[1].y, "□");	
	}

	// 뱀 머리 이동
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
	drawChar(snake[0].x, snake[0].y, "■");	//새로운 좌표에 뱀 머리 그림
}

int checkSnake(POS* snake, int len)
{
	int i;

	//머리의 좌표와 벽의 좌표가 만나면 중지
	if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == 34 || snake[0].y == 20)
	{
		return 0;
	}
	
	//머리의 좌표와 몸통의 좌표가 만나면 중지
	for (i = 1; i < len; i++)
	{
		if (snake[0].x == snake[i].x&&snake[0].y == snake[i].y)
		{
			return 0;
		}
	}

	return 1;
}

int firstSnake(POS* snake, int len)
{
	int i;
	for (i = 0; i<len; i++)
	{
		//좌표설정,출력
		snake[i].x = 15 + i;
		snake[i].y = 10;
		drawChar(snake[i].x, snake[i].y, "□");
	}

	//입력값 초기화
	getch() == '\n';
	return 1;
}
