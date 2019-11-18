#include "DxLib.h"
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

    bool softisEnd = false;
    while (softisEnd&&ProcessMessage() != -1) {

        ScreenFlip();
        ClearDrawScreen();
        WaitTimer(33);
    }

    DxLib_End();				// �c�w���C�u�����g�p�̏I������

    return 0;				// �\�t�g�̏I�� 
}