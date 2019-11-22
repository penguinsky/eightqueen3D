#include"header.h"

int mouseMoveX(void) {
    static int x = 0;
    if (x == 0) {
        GetMousePoint(&x, NULL);
    }

    int newx = 0;
    GetMousePoint(&newx, NULL);
    int diff = newx - x;
    x = newx;
    return diff;
}

int mouseMoveY(void) {
    static int y = 0;
    if (y == 0) {
        GetMousePoint(&y, NULL);
    }

    int newy = 0;
    GetMousePoint(&newy, NULL);
    int diff = newy - y;
    y = newy;
    return diff;
}

bool mouseLclick(void) {
    static bool pressed = false;
    bool click = false;

    if (GetMouseInput() & MOUSE_INPUT_LEFT) {
        if (pressed == false) {
            click = true;
            pressed = true;
        }
    } else {
        pressed = false;
    }
    return click;
}

bool mouseRclick(void) {
    static bool pressed = false;
    bool click = false;

    if (GetMouseInput() & MOUSE_INPUT_RIGHT) {
        if (pressed == false) {
            click = true;
            pressed = true;
        }
    } else {
        pressed = false;
    }
    return click;
}

int mouseScrool(void) {
    return GetMouseWheelRotVol();
}
