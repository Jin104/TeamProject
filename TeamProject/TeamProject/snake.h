#pragma once

typedef struct {
	int x, y;
}  POS;

#define MAX 100

void moveSnake(POS* snake, int len); //���̵�
int checkSnake(POS* snake, int len); //�浹üũ
int firstSnake(POS* snake, int len); //�� �ʱ���ġ
void resetItem(int len); //�Ȱ�ġ��
//void resetItem2(int len);