#ifndef DEF_ELS_HEAD
#define DEF_ELS_HEAD

#include <windows.h>
#include <time.h>

#define DEF_TIMER1 1234
void OnPaint(HDC hDc);
//��ʾ����
void PaintSqure(HDC hMemDc);
//���������
int CreateRandSquare();
//�������������
void CopySquareToBack();

void OnCreate();

//��������
void SquareDown();
//��������
void SquareLeft();
//��������
void SquareRight();

//��ʱ����Ӧ����
void OnTimer(HWND hWnd);
//ENTER�س���
void OnReturn(HWND hWnd);
void OnLeft(HWND hWnd);
void OnRight(HWND hWnd);
void OnDown(HWND hWnd);
void OnChangeSquare(HWND hWnd);
//����ͣ�������,0���������䣬1��������
int CanSquareDown();
int CanSquareDown2();
int CanSquareLeft();
int CanSquareLeft2();
int CanSquareRight();
int CanSquareRight2();
int CanSquareChangeShape();
int CanLineSquareChange();
int CanGameOver(HWND hWnd);
//��1���2,�ﵽ��������Ч��
void Change1To2();
void ChangeSquare();//��ת���༸�ַ���
void ChangeLineSquare();//��ת��������״
void ToFullLoseSquare();//�ж������Ƿ�ȱ��
void DestroyOneLineSquare();//��������
//��ʾ2
void ShowSquare2(HDC hMemDc);
void ShowScore(HDC hMemDc);


#endif