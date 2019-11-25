#include"header.h"

int board_size = 1;

void setBoardSize(int size) {
    if (IN(1, size, BOARD_MAXSIZE)) {
        board_size = size;
    }
}
