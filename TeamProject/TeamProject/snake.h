#pragma once

// x,y��ǥ�� ����
typedef struct {
	int x, y;
}  POS;

#define MAX 100

void moveSnake(POS* snake, int len); //���̵�
int checkSnake(POS* snake, int len); //�浹üũ
int firstSnake(POS* snake, int len); //�� �ʱ���ġ