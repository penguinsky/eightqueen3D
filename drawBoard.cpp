#include"header.h"
#include<stdio.h>
void drawBoard(const short(*board)[BOARDSIZE]) {
    static int y, x;
    static int leftupX  = -12;
    static int leftupY  = 20;
    static int boxsizeX = 2;
    static int boxsizeY = 2;
    static int modelQ;
    static int modelq;
    static int modelA;
    static int modelK;

    static bool first = true;
    if (first) {
        first = false;
        modelQ = MV1LoadModel("resource/test.mqo");
        modelA = MV1LoadModel("resource/aka.mqo");
        modelK = MV1LoadModel("resource/ki.mqo");
        MV1SetScale(modelQ, VECTOR{ 0.05f, 0.05f, 0.05f });
        MV1SetScale(modelA, VECTOR{ 0.05f, 0.05f, 0.05f });
        MV1SetScale(modelK, VECTOR{ 0.05f, 0.05f, 0.05f });
        SetCameraNearFar(0.1f, 100.0f);
        SetCameraPositionAndTarget_UpVecY(VGet(0, 30, -10), VGet(0.0f, 10.0f, 0.0f));
        //SetCameraPositionAndTarget_UpVecY(VGet(0, 20, -20), VGet(0.0f, 10.0f, 0.0f));
    }
    if (modelQ == -1) {
        DrawCircle(100,100,50, GetColor(255, 255, 255));
        return;
    }

    for (y = 0; y < BOARDSIZE; y++) {
        for (x = 0; x < BOARDSIZE; x++) {
            float QX = leftupX + boxsizeX * x * 1.5f;
            float QY = leftupY - boxsizeY * y * 1.5f;
            {
                float QX = leftupX + boxsizeX * x * 1.5f;
                float QY = leftupY - boxsizeY * y * 1.5f;
                if ((x + y) % 2) {
                    MV1SetPosition(modelA, VECTOR{ QX,0,QY });
                    MV1DrawModel(modelA);
                } else {
                    MV1SetPosition(modelK, VECTOR{ QX,0,QY });
                    MV1DrawModel(modelK);
                }
            }
            if (board[x][y] == QUEEN) {
                MV1SetPosition(modelQ, VECTOR{ QX,0,QY });
                MV1DrawModel(modelQ);
            }
        }
    }
}
