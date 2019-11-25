#include"header.h"

void initBoard(short(*board)[BOARD_MAXSIZE]) {
    for (int x = 0;x < board_size;x++) {
        for (int y = 0;y < board_size;y++) {
            board[x][y] = NONE;
        }
    }
}
