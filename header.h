#pragma once
#include"DxLib.h"
#include<stdbool.h>
#include"general_macros.h"

enum squaresHave {
    NONE,
    QUEEN
};

#define BOARD_MAXSIZE 10//盤面のマス目の最大数
extern int board_size;
void setBoardSize(int size);
void controlBoardSize(void);
void displayBoardSize(void);

bool setPattern(const short(*board)[BOARD_MAXSIZE]);	//boardをパターンに圧縮して記録する
bool patternFromNum(int num, short(*board)[BOARD_MAXSIZE]);		//記録したパターンからboardを再現する
bool checkExist(bool* exist, int num, int x, int y);
void freePattern(void);
void writePattern(FILE* file);
void readPattern(FILE* file);

void initBoard(short(*board)[BOARD_MAXSIZE]);			//boardを初期化(0埋め)する
void calcPattern(void);	//8クイーンを満たすパターンを全て計算し、setPattern()で記録する
int  draw(short(*board)[BOARD_MAXSIZE], int num);				//記録したパターン全てをdrawBoard()で描画する
void drawBoard(const short(*board)[BOARD_MAXSIZE]);		//boardから盤面を描画する
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