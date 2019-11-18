#include"header.h"
#include<stdio.h>

void draw(short(*board)[BOARDSIZE])
{
    getPattern(board);
    drawBoard(board);
}
