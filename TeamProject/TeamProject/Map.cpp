#include "start.h"


int selectMenu()
{
	int key,i;
	system("cls");

	printf("\n\n\n");
	puts("        □□□  □    □    □□   □    □  □□□      □□      □□    □      □  □□□    ");
	puts("        □      □□  □  □    □ □  □    □        □        □    □  □□  □□  □        ");
	puts("        □□□  □□  □  □□□□ □□      □□□    □  □□  □□□□  □  □  □  □□□    ");
	puts("            □  □  □□  □    □ □  □    □        □    □  □    □  □  □  □  □        ");
	puts("            □  □  □□  □    □ □    □  □        □    □  □    □  □  □  □  □        ");
	puts("        □□□  □    □  □    □ □    □  □□□      □□    □    □  □  □  □  □□□    ");
	
	drawChar(20, 11, "Made by Que Sera Sera");
	drawChar(20, 13, " ─────────\n");
	drawChar(20, 14, "│1. 게임시작     │\n");
	drawChar(20, 15, "│2. 게임방법     │\n");
	drawChar(20, 16, "│3. 랭킹보기     │\n");
	drawChar(20, 17, "│4. 종료         │\n");
	drawChar(20, 18, " ─────────\n");

	scanf("%d", &key);

	return key;
}

void howPlay()
{
	system("cls");
	drawChar(10, 5, "ESC 일시정지");
	drawChar(10, 8, " 조작키");
	drawChar(10, 10, "   ↑");
	drawChar(10, 11, "←    →");
	drawChar(10, 12, "   ↓");
	drawChar(20, 11, "먹이(♡)를 먹으면 꼬리가 하나씩 증가하고 속도가 증가합니다.");
	drawChar(20, 12, "벽이나 몸에 박으면 게임이 종료되고 이름을 적으면 됩니다.");
	drawChar(30, 17, "뒤로가기 : 아무키나 누르세요.");
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
		drawChar(0, i, "▣");
		drawChar(34, i, "▣");
	}
	drawChar(0, 20, "▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣");

	drawChar(27, 22, "ESC 일시정지");
}


void drawChar(int x, int y, char* s)
{
	COORD Pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	printf("%s", s);
}

//void setColorRed()
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//}
//
//void setColorWhite()
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//}