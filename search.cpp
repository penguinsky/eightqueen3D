#include"header.h"
#include"Pattern.h"
#include"square.h"

static int noexist[SIZE * MAGNI_MAX];
static int  result[SIZE * MAGNI_MAX];
static int resultp;
static short sboard[BOARD_MAXSIZE][BOARD_MAXSIZE];

static int scrool = 0;
static int line = 1;

void wheelcontrol(int add);

void queenSwitch(int x, int y) {
    bool narrow = sboard[x][y] ^= QUEEN;
    bool exist;
    resultp = 0;
    for (int num = 0; checkExist(&exist, num, x, y);num++) {
        if (!exist) {
            if (narrow) {
                noexist[num]++;
            } else {
                noexist[num]--;
            }
        }

        if (noexist[num] == 0) {
            result[resultp++] = num;
        }
    }
}

void searchInit(void) {
    resultp = memory_now;
    for (int i = 0;i < resultp;i++) {
        noexist[i] = 0;
         result[i] = i;
    }
    scrool = 0;
    initBoard(sboard);
}

#define WINDOW_X 490
#define WINDOW_Y 0

void searchMod(void) {
    int x, y;

    static bool pressed = false;
    GetMousePoint(&x, &y);
    if (
        !IN(WINDOW_X, x, WINDOW_X + BOX * board_size) ||
        !IN(WINDOW_Y, y, WINDOW_Y + BOX * board_size) ||
        !mouseLclick(&pressed)
        ) {
        return;
    }

    int operateX = (x - WINDOW_X) / BOX;
    int operateY = (y - WINDOW_Y) / BOX;
    queenSwitch(operateX, operateY);
    scrool = 0;
}

void displaySearch(void) {
    drawBoard2D(WINDOW_X, WINDOW_Y, sboard);
}

void displayResult(void) {
    const static unsigned int white = GetColor(255, 255, 255);
    const static int x = 500;
    const static int y = 200;
    const static int column = 3;
    line = resultp / column + 1;
    const static int between = 10;
    int boardsides = BOX * board_size;

    DrawFormatString(x, y, white, "ŠY“–F%3dŒ", resultp);
    for (int i = 0;i < resultp;i++) {
        int x = (boardsides + between) * (i % column) + between;
        int y = (boardsides + between) * ((i / column) - scrool) + between;

        short board[BOARD_MAXSIZE][BOARD_MAXSIZE];
        patternFromNum(result[i], board);
        drawBoard2D(x, y, board);
    }
//    int scroolength = 3 / line * 200;
//    DrawBox(WINDOW_X - 30, 0, WINDOW_X - 20, 200, white, true);
//    DrawBox(WINDOW_X - 30, scrool * scroolength, WINDOW_X - 20, (scrool + 1) * scroolength, GetColor(200,200,200), true);
}

void wheelcontrol(int add) {
    int cap = line - 1;
    if (add > 0) {
        scrool = (scrool + add) < cap ? (scrool + add) : cap;
    } else if (add < 0) {
        scrool = (scrool + add) >= 0 ? (scrool + add) : 0;
    }
}

int controlResult(void) {
    int ret = -1;
    const static int between = 10;
    const static int boardsides = BOX * board_size;

    wheelcontrol(GetMouseWheelRotVol());

    static bool pressed = false;
    if (!mouseLclick(&pressed)) {
        return ret;
    }

    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);
    for (int x = 0;x < 3;x++) {
        for (int y = 0;y < 3;y++) {
            int x1 = (boardsides + between) * x + between;
            int y1 = (boardsides + between) * y + between;
            int x2 = (boardsides + between) * x + between + boardsides;
            int y2 = (boardsides + between) * y + between + boardsides;
            if (
                IN(x1, mouseX, x2) &&
                IN(y1, mouseY, y2)
                ) {
                ret = scrool * 3 + x + y * 3;
            }
        }
    }
    return ret;
}

int getNext(int resultnum) {
    resultnum = (resultnum + 1) % resultp;
    return resultnum;
}
int getPrev(int resultnum) {
    resultnum = resultnum - 1 >= 0 ? resultnum - 1 : resultp - 1;
    return resultnum;
}
int getResult(int resultnum) {
    return result[resultnum];
}
