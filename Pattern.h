#pragma once
#include"header.h"

#define SIZE 100	//一度に確保する容量(short[BOARD_MAXSIZE]単位)
#define MAGNI_MAX 50	//確保する容量の最大値

extern short(*zipptr)[BOARD_MAXSIZE];
extern int memory_now;
