#pragma once

typedef struct {
	int x, y;
}  POS;

#define MAX 100

void moveSnake(POS* snake, int len); //뱀이동
int checkSnake(POS* snake, int len); //충돌체크
int firstSnake(POS* snake, int len); //뱀 초기위치
