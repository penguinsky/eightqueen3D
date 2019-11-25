#include"header.h"

void mouseMove(int* x, int* y) {
    static int oldx = 0;
    static int oldy = 0;
    if (oldx == 0 && oldy == 0) {
        GetMousePoint(&oldx, &oldy);
    }

    int newx = 0, newy = 0;
    GetMousePoint(&newx, &newy);

    if (x != NULL && y != NULL) {
        *x = newx - oldx;
        *y = newy - oldy;
    }
    oldx = newx;
    oldy = newy;
}

bool mouseLclick(bool* pressed) {
    bool click = false;

    if (GetMouseInput() & MOUSE_INPUT_LEFT) {
        if (*pressed == false) {
            click = true;
            *pressed = true;
        }
    } else {
        *pressed = false;
    }
    return click;
}

bool mouseRclick(bool* pressed) {
    bool click = false;

    if (GetMouseInput() & MOUSE_INPUT_RIGHT) {
        if (*pressed == false) {
            click = true;
            *pressed = true;
        }
    } else {
        *pressed = false;
    }
    return click;
}
