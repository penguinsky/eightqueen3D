#include"header.h"

const static int X = 550;
const static int Y = 280;
static int size = board_size;

void addSize(int add);

void controlBoardSize(void) {
    DrawBox(X-8, Y+25, X+45, Y+40, GetColor(150, 150, 150), true);
    DrawBox(X-10, Y, X+ 2, Y+18, GetColor(150, 150, 150), true);
    DrawBox(X+34, Y, X+47, Y+18, GetColor(150, 150, 150), true);

    static bool pressed = false;
    if (!mouseLclick(&pressed)) {
        return;
    }

    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);
    if (
        IN(X -  8, mouseX, X + 45) &&
        IN(Y + 25, mouseY, Y + 40)
        ) {
        setBoardSize(size);
        calcPattern();
    } else if (
        IN(X-10, mouseX, X+2) &&
        IN(Y, mouseY, Y + 18)
        ) {
        addSize(-1);
    } else if (
        IN(X + 34, mouseX, X + 47) &&
        IN(Y, mouseY, Y + 18)
        ) {
        addSize(1);
    }
}

void addSize(int add) {
    if (IN(1, size + add, 10)) {
        size += add;
    }
}

void applyBoardSize(void) {

}

void displayBoardSize(void) {
    const static unsigned int white = GetColor(255, 255, 255);
    const static unsigned int black = GetColor(0, 0, 0);

    DrawBox(X + 8, Y-2, X + 29, Y + 17, black, true);
    DrawFormatString(X-8, Y, white, "- %2d +", size);
    DrawFormatString(X-8, Y + 25, white, "[“K—p]", size);
}
