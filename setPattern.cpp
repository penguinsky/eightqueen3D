#include"header.h"
#include"Pattern.h"
#include<stdlib.h>

int memory_now = 0;
short(*zipptr)[BOARD_MAXSIZE] = NULL;

static int size_magni;

bool keepMemorySize(int memory_now);

bool setPattern(const short(*board)[BOARD_MAXSIZE]) {
    if (keepMemorySize(memory_now) == false) {
        return false;
    }

    for (int x = 0;x < board_size;x++)
        for (int y = 0;y < board_size;y++)
            if (board[x][y] == QUEEN) {
                zipptr[memory_now][y] = x;
                break;
            }

    memory_now++;
    return true;
}

bool keepMemorySize(int memory_now) {
    bool ret = true;
    if (memory_now >= SIZE * size_magni) {	//—e—Ê‚ª‘«‚è‚Ä‚È‚¢‚È‚ç
        if (size_magni < MAGNI_MAX) {		//—e—Ê‚ÌŠù’è‚ÌÅ‘å’l‚ð’´‚¦‚È‚¢‚È‚ç
            void* tmp;

            int capacity = sizeof(short) * BOARD_MAXSIZE * SIZE * ++size_magni;
            tmp = realloc((void*)zipptr, capacity);

            if (tmp == NULL)	//realloc()‚ªŽ¸”s‚µ‚½‚ç
                ret = false;
            else
                zipptr = (short(*)[BOARD_MAXSIZE])tmp;
        } else {
            ret = false;
        }
    }

    return ret;
}

void freePattern(void) {
    free(zipptr);
    zipptr = NULL;
    memory_now = 0;
    size_magni = 0;
}

void readPattern(FILE* file) {
    bool loop = true;
    while (loop) {
        keepMemorySize(memory_now);
        for (int y = 0;y < board_size;y++) {
            if (fscanf_s(file, "%hd,", &zipptr[memory_now][y]) == EOF) {
                loop = false;
            }
        }
        if (loop) {
            memory_now++;
        }
    }
}
