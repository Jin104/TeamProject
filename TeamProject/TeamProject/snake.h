#pragma once

typedef struct {
	int x, y;
}  POS;

#define MAX 100

void move_snake(POS* snake, int len); //���̵�
int check_snake(POS* snake, int len); //�浹üũ
int first_snake(POS* snake, int len); //�� �ʱ���ġ