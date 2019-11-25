#include "header.h"
#include "Pattern.h"

bool patternFromNum(int num, short(*board)[BOARD_MAXSIZE]) {
    if (!IN(0, num, memory_now - 1)) {
        return false;
    }

    initBoard(board);
    for (int y = 0;y < board_size;y++) {
        int queen_pos = zipptr[num][y];
        board[queen_pos][y] = QUEEN;
    }

    return true;
}

bool checkExist(bool* exist, int num, int x, int y) {
    if (!IN(0, num, memory_now - 1)) {
        return false;
    } else {
        *exist = (zipptr[num][y] == x);
        return true;
    }
}

void writePattern(FILE* file) {
    for (int num = 0;num < memory_now;num++) {
        for (int y = 0;y < board_size;y++) {
            fprintf(file, "%d,", zipptr[num][y]);
        }
        fprintf(file,"\n");
    }
}
