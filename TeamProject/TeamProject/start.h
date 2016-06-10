#pragma once
#include "rank.h"
#include "snake.h"
#include "map.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void Go(); // 실행
void gameStart();  //게임 실행

//먹이의 생성좌표와 뱀의 좌표가 겹치지않게.
void resetItem(int len); 


#define ESC 0x1B

//#define LEFT 75
//#define RIGHT 77
//#define UP 72
//#define DOWN 80