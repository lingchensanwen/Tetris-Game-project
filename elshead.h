#ifndef DEF_ELS_HEAD
#define DEF_ELS_HEAD

#include <windows.h>
#include <time.h>

#define DEF_TIMER1 1234
void OnPaint(HDC hDc);
//显示方块
void PaintSqure(HDC hMemDc);
//产生随机块
int CreateRandSquare();
//随机块贴进背景
void CopySquareToBack();

void OnCreate();

//方块下落
void SquareDown();
//方块左移
void SquareLeft();
//方块右移
void SquareRight();

//定时器响应函数
void OnTimer(HWND hWnd);
//ENTER回车键
void OnReturn(HWND hWnd);
void OnLeft(HWND hWnd);
void OnRight(HWND hWnd);
void OnDown(HWND hWnd);
void OnChangeSquare(HWND hWnd);
//方块停在最底下,0不可以下落，1可以下落
int CanSquareDown();
int CanSquareDown2();
int CanSquareLeft();
int CanSquareLeft2();
int CanSquareRight();
int CanSquareRight2();
int CanSquareChangeShape();
int CanLineSquareChange();
int CanGameOver(HWND hWnd);
//让1变成2,达到持续下落效果
void Change1To2();
void ChangeSquare();//旋转其余几种方块
void ChangeLineSquare();//旋转长条的形状
void ToFullLoseSquare();//判断条形是否缺块
void DestroyOneLineSquare();//消除方块
//显示2
void ShowSquare2(HDC hMemDc);
void ShowScore(HDC hMemDc);


#endif