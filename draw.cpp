#include"header.h"
#include<stdio.h>

int draw(short(*board)[BOARD_MAXSIZE], int num)
{
    static bool first = true;
    static int snum = -1;
    if (snum != num) {
        patternFromNum(getResult(num), board);
        snum = num;
    }

    int wheel = GetMouseWheelRotVol();
    for (int i = 0;i < abs(wheel);i++) {
        if (wheel > 0) {
            num = getNext(num);
        } else {
            num = getPrev(num);
        }
    }

    static bool pressed = false;
    if (mouseLclick(&pressed)) {
        return -1;
    }

    drawBoard(board);

    return num;
}
