#include "start.h"


int selectMenu()
{
	int key,i;
	system("cls");

	printf("\n\n\n");
	puts("        ����  ��    ��    ���   ��    ��  ����      ���      ���    ��      ��  ����    ");
	puts("        ��      ���  ��  ��    �� ��  ��    ��        ��        ��    ��  ���  ���  ��");
	puts("        ����  ���  ��  ����� ���      ����    ��  ���  �����  ��  ��  ��  ����");
	puts("            ��  ��  ���  ��    �� ��  ��    ��        ��    ��  ��    ��  ��  ��  ��  ��");
	puts("            ��  ��  ���  ��    �� ��    ��  ��        ��    ��  ��    ��  ��  ��  ��  ��");
	puts("        ����  ��    ��  ��    �� ��    ��  ����      ���    ��    ��  ��  ��  ��  ����");
	
	drawChar(22, 11, "Made by Jin");
	drawChar(20, 13, " ������������������\n");
	drawChar(20, 14, "��1. ���ӽ���     ��\n");
	drawChar(20, 15, "��2. ���ӹ��     ��\n");
	drawChar(20, 16, "��3. ��ŷ����     ��\n");
	drawChar(20, 17, "��4. ����         ��\n");
	drawChar(20, 18, " ������������������\n");

	scanf("%d", &key);

	return key;
}

void howPlay()
{
	system("cls");
	drawChar(10, 5, "ESC �Ͻ�����");
	drawChar(10, 8, " ����Ű");
	drawChar(10, 10, "   ��");
	drawChar(10, 11, "��    ��");
	drawChar(10, 12, "   ��");
	drawChar(20, 11, "����(��)�� ������ ������ �ϳ��� �����ϰ� �ӵ��� �����մϴ�.");
	drawChar(20, 12, "���̳� ���� ������ ������ ����ǰ� �̸��� ������ �˴ϴ�.");
	drawChar(30, 17, "�ڷΰ��� : �ƹ�Ű�� ��������.");
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

	drawChar(27, 22, "ESC �Ͻ�����");
}


void drawChar(int x, int y, char* s)
{
	COORD Pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	printf("%s", s);
}