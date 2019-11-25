#include"header.h"
#include"square.h"
#include<stdio.h>

void drawBoard(const short(*board)[BOARD_MAXSIZE]) {
    static int y, x;
    static int leftupX  = -12;
    static int leftupY  = 20;
    static int boxsizeX = 2;
    static int boxsizeY = 2;
    static int modelQ = MV1LoadModel("resource/test.mqo");
    static int modelA = MV1LoadModel("resource/aka.mqo");
    static int modelK = MV1LoadModel("resource/ki.mqo");

    static bool first = true;
    if (first) {
        first = false;
        MV1SetScale(modelQ, VECTOR{ 0.05f, 0.05f, 0.05f });
        MV1SetScale(modelA, VECTOR{ 0.05f, 0.05f, 0.05f });
        MV1SetScale(modelK, VECTOR{ 0.05f, 0.05f, 0.05f });
        SetCameraNearFar(0.1f, 100.0f);
        SetCameraPositionAndTarget_UpVecY(VGet(0, 30, -10), VGet(0.0f, 10.0f, 0.0f));
    }
    if (modelQ == -1) {
        DrawCircle(100,100,50, GetColor(255, 255, 255));
        return;
    }

    for (y = 0; y < board_size; y++) {
        for (x = 0; x < board_size; x++) {
            float QX = leftupX + boxsizeX * x * 1.5f;
            float QY = leftupY - boxsizeY * y * 1.5f;

            if ((x + y) % 2) {
                MV1SetPosition(modelA, VECTOR{ QX,0,QY });
                MV1DrawModel(modelA);
            } else {
                MV1SetPosition(modelK, VECTOR{ QX,0,QY });
                MV1DrawModel(modelK);
            }

            if (board[x][y] == QUEEN) {
                MV1SetPosition(modelQ, VECTOR{ QX,0,QY });
                MV1DrawModel(modelQ);
            }
        }
    }
}

void drawBoard2D(int boardX, int boardY, const short(*board)[BOARD_MAXSIZE]) {
    const static unsigned int black = GetColor(0, 0, 0);
    const static unsigned int white = GetColor(255, 255, 255);
    const static unsigned int red = GetColor(255, 0, 0);

    for (int y = 0;y < board_size;y++) {
        for (int x = 0;x < board_size;x++) {
            unsigned int color;
            if ((x + y) % 2) {
                color = black;
            } else {
                color = white;
            }

            //”Õ–Ê•`‰æ
            DrawBox(
                boardX + x * BOX,
                boardY + y * BOX,
                boardX + (x + 1) * BOX,
                boardY + (y + 1) * BOX,
                color,
                1
            );

            //ƒNƒC[ƒ“•`‰æ
            if (board[x][y] == QUEEN) {
                DrawCircle(
                    (int)(boardX + (x + 0.5) * BOX),
                    (int)(boardY + (y + 0.5) * BOX),
                    BOX / 2 - 2,
                    red
                );
            }
        }
    }
}
