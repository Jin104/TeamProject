#pragma once
#include "rank.h"
#include "snake.h"
#include "map.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void Go(); // ����
void gameStart();  //���� ����

//������ ������ǥ�� ���� ��ǥ�� ��ġ���ʰ�.
void resetItem(int len); 


#define ESC 0x1B

//#define LEFT 75
//#define RIGHT 77
//#define UP 72
//#define DOWN 80