#include"header.h"
#include<stdio.h>

bool draw(short(*board)[BOARDSIZE])
{
    static bool first = true;
    static bool pressed = false;
    if (first) {
        first = false;
        if (!getPattern(board))return false;
    }else if (CheckHitKey(KEY_INPUT_SPACE)) {
        if (!pressed) {
            if (!getPattern(board))return false;
            pressed = true;
        }
    } else {
        pressed = false;
    }
    drawBoard(board);
    return true;
}
