#include "map.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>


int select_menu()
{
	int key;
	system("cls");
	printf("1. ���ӽ���\n");
	printf("2. ���ӹ��\n");
	printf("3. ����\n");

	scanf("%d", &key);

	return key;
}

//���� ����70 ����21
void draw_map()
{
	int i;

	system("cls");
	draw_char(0, 0, "������������������������������������");
	for (i = 1;i < 20;i++)
	{
		draw_char(0, i, "��");
		draw_char(34, i, "��");
	}
	draw_char(0, 20, "������������������������������������");
}


//ȭ���� Ư�� ��ġ�� �̵��� ����ϴ� �Լ�
void draw_char(int x, int y, char* s)
{
	COORD Pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	printf("%s", s);
}