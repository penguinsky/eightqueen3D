#include "DxLib.h"
#include "header.h"
#include <stdbool.h>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);
    SetMainWindowText("EightQueen3D");

    if (DxLib_Init() == -1)		// �c�w���C�u��������������
        return -1;			// �G���[���N�����璼���ɏI��

    SetWindowSizeExtendRate(2);
    SetDrawScreen(DX_SCREEN_BACK);
    SetFullScreenScalingMode(DX_FSSCALINGMODE_NEAREST);

    //�G�C�g�N�C�[���̎Z�o
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

    DxLib_End();				// �c�w���C�u�����g�p�̏I������

    return 0;				// �\�t�g�̏I�� 
}
