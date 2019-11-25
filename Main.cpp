#include "DxLib.h"
#include "header.h"
#include <stdbool.h>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);
    SetMainWindowText("EightQueen3D");

    if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
        return -1;			// エラーが起きたら直ちに終了

    SetWindowSizeExtendRate(2);
    SetDrawScreen(DX_SCREEN_BACK);
    SetFullScreenScalingMode(DX_FSSCALINGMODE_NEAREST);

    //エイトクイーンの算出
    short board[BOARD_MAXSIZE][BOARD_MAXSIZE];
    setBoardSize(8);
    calcPattern();

    int scene = -1;
    bool tonext = true;
    while (tonext && ProcessMessage() != -1) {

        switch(scene) {
            case -1:
                SetBackgroundColor(100, 100, 0);
                controlBoardSize();
                displayBoardSize();
                searchMod();
                displaySearch();
                displayResult();
                scene = controlResult();
                break;
            default:
                SetBackgroundColor(0, 0, 0);
                scene = draw(board, scene);
        }


        ScreenFlip();
        ClearDrawScreen();
        WaitTimer(33);
    }
    freePattern();

    DxLib_End();				// ＤＸライブラリ使用の終了処理

    return 0;				// ソフトの終了 
}
