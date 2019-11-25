#include"header.h"

bool checkQueen(short(*board)[BOARD_MAXSIZE], int x, int y);
void recursive(short(*board)[BOARD_MAXSIZE], int y);

void calcPattern(void) {
    #define STRSIZE 20
    char name[STRSIZE];
    snprintf(name, STRSIZE, "2_%d.txt", board_size);

    short board[BOARD_MAXSIZE][BOARD_MAXSIZE];
    initBoard(board);
    freePattern();
    FILE* file;
    if (fopen_s(&file, name, "r") == 0) {
        readPattern(file);
        fclose(file);
    } else {
        recursive(board, 0);
        if (fopen_s(&file, name, "w") == 0) {
            writePattern(file);
            fclose(file);
        }
    }

    searchInit();
}

void recursive(short(*board)[BOARD_MAXSIZE], int y) {
    for (int x = 0;x < board_size;x++) {
        if (checkQueen(board, x, y)) {
            board[x][y] = QUEEN;
            if (y == board_size - 1) {
                setPattern(board);
            } else {
                recursive(board, y + 1);
            }
            board[x][y] = NONE;
        }
    }
}

bool checkQueen(short(*board)[BOARD_MAXSIZE], int x, int y) {
    bool ret = true;

    for (int i = 1;i <= y;i++) {
        if (board[x][y - i] == QUEEN)
            ret = false;

        if (x - i >= 0)
            if (board[x - i][y - i] == QUEEN)
                ret = false;

        if (x + i < board_size)
            if (board[x + i][y - i] == QUEEN)
                ret = false;
    }

    return ret;
}
