#pragma once
#include"DxLib.h"
#include<stdbool.h>
#include"general_macros.h"

enum squaresHave {
    NONE,
    QUEEN
};

#define BOARD_MAXSIZE 10//�Ֆʂ̃}�X�ڂ̍ő吔
extern int board_size;
void setBoardSize(int size);
void controlBoardSize(void);
void displayBoardSize(void);

bool setPattern(const short(*board)[BOARD_MAXSIZE]);	//board���p�^�[���Ɉ��k���ċL�^����
bool patternFromNum(int num, short(*board)[BOARD_MAXSIZE]);		//�L�^�����p�^�[������board���Č�����
bool checkExist(bool* exist, int num, int x, int y);
void freePattern(void);
void writePattern(FILE* file);
void readPattern(FILE* file);

void initBoard(short(*board)[BOARD_MAXSIZE]);			//board��������(0����)����
void calcPattern(void);	//8�N�C�[���𖞂����p�^�[����S�Čv�Z���AsetPattern()�ŋL�^����
int  draw(short(*board)[BOARD_MAXSIZE], int num);				//�L�^�����p�^�[���S�Ă�drawBoard()�ŕ`�悷��
void drawBoard(const short(*board)[BOARD_MAXSIZE]);		//board����Ֆʂ�`�悷��
void drawBoard2D(int boardX, int boardY, const short(*board)[BOARD_MAXSIZE]);

void mouseMove(int* x, int* y);
bool mouseLclick(bool* pressed);
bool mouseRclick(bool* pressed);

void searchInit(void);
void searchMod(void);
void displaySearch(void);
void displayResult(void);
int controlResult(void);
int getNext(int resultnum);
int getPrev(int resultnum);
int getResult(int resultnum);