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
    short board[BOARDSIZE][BOARDSIZE];
    initBoard(board);
    calcPattern(board, 0);

    bool tonext = true;  
    while (tonext&&ProcessMessage() != -1) {

        tonext = draw(board); 

        ScreenFlip();
        ClearDrawScreen();
        WaitTimer(33);
    }

    DxLib_End();				// �c�w���C�u�����g�p�̏I������

    return 0;				// �\�t�g�̏I�� 
}
