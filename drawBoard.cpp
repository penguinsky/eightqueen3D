#include"header.h"
#include<stdio.h>
void drawBoard(const short(*board)[BOARDSIZE]) {
    int y, x;
    int leftupX  = 50;
    int leftupY  = 50;
    int boxsizeX = 50;
    int boxsizeY = 50;

    for (y = 0; y < BOARDSIZE; y++) {
        for (x = 0; x < BOARDSIZE; x++) {
            int x1 = leftupX + boxsizeX * x;
            int y1 = leftupY + boxsizeY * y;
            int x2 = leftupX + boxsizeX * (x + 1) - 10;
            int y2 = leftupY + boxsizeY * (y + 1) - 10;
            if (board[x][y] == QUEEN)
                DrawBox(x1, y1, x2, y2, 1000, 1);
            else
                DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), 1);
        }
    }
}
