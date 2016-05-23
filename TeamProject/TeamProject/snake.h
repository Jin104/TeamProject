#pragma once

typedef struct {
	int x, y;
}  POS;

#define MAX 100

void move_snake(POS* snake, int len); //뱀이동
int check_snake(POS* snake, int len); //충돌체크
int first_snake(POS* snake, int len); //뱀 초기위치