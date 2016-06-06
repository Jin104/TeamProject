#pragma once
#include "feed.h"
#include "snake.h"
#include "map.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void Go();
void gameStart();
void ranking(int score);
void showRanking();

#define ESC 0x1B
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80