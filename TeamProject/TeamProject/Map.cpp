#include "start.h"


int selectMenu()
{
	int key;
	system("cls");
	printf("1. ���ӽ���\n");
	printf("2. ���ӹ��\n");
	printf("3. ��ŷ����\n");
	printf("4. ����\n");

	scanf("%d", &key);

	return key;
}

void howPlay()
{
	system("cls");
	drawChar(10, 9, "ESC �Ͻ�����");
	drawChar(10, 10, "����Ű�� ����Ͽ� ���� �����δ�.");
	drawChar(10, 11, "����(��)�� ������ ������ �ϳ��� �����Ѵ�.");
	drawChar(10, 12, "���̳� ���� ������ ���ӿ���");
	drawChar(25, 20, "�ڷΰ��� : �ƹ�Ű�� �������");
	system("pause>null");
	system("cls");
}

void drawMap()
{
	int i;

	system("cls");
	drawChar(0, 0, "�ââââââââââââââââââââââââââââââââââ�");

	for (i = 1;i < 20;i++)
	{
		drawChar(0, i, "��");
		drawChar(34, i, "��");
	}
	drawChar(0, 20, "�ââââââââââââââââââââââââââââââââââ�");

	drawChar(10, 22, "ESC �Ͻ�����");
}


void drawChar(int x, int y, char* s)
{
	COORD Pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	printf("%s", s);
}