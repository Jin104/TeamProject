#include "start.h"


int selectMenu()
{
	int key;
	system("cls");
	printf("1. 게임시작\n");
	printf("2. 게임방법\n");
	printf("3. 랭킹보기\n");
	printf("4. 종료\n");

	scanf("%d", &key);

	return key;
}

void howPlay()
{
	system("cls");
	drawChar(10, 9, "ESC 일시정지");
	drawChar(10, 10, "방향키를 사용하여 뱀을 움직인다.");
	drawChar(10, 11, "먹이(♡)를 먹으면 꼬리가 하나씩 증가한다.");
	drawChar(10, 12, "벽이나 몸에 박으면 게임오버");
	drawChar(25, 20, "뒤로가기 : 아무키나 누르면됨");
	system("pause>null");
	system("cls");
}

void drawMap()
{
	int i;

	system("cls");
	drawChar(0, 0, "▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣");

	for (i = 1;i < 20;i++)
	{
		drawChar(0, i, "□");
		drawChar(34, i, "□");
	}
	drawChar(0, 20, "▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣");

	drawChar(10, 22, "ESC 일시정지");
}


void drawChar(int x, int y, char* s)
{
	COORD Pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	printf("%s", s);
}