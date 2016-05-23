#pragma once

typedef struct {
	int x, y;
} POS;

void move_snake(POS* snake, int len);
int check_snake(POS* snake, int len);