#include "DxLib.h"
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

    bool softisEnd = false;
    while (softisEnd&&ProcessMessage() != -1) {

        ScreenFlip();
        ClearDrawScreen();
        WaitTimer(33);
    }

    DxLib_End();				// ＤＸライブラリ使用の終了処理

    return 0;				// ソフトの終了 
}