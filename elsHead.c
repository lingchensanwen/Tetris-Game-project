#include "elshead.h"
//��������
char g_arrBackGround[20][10] = {0};//int 200 * 4 800 200 ��Լ�ռ�
char g_arrSquare[2][4] = {0};
int g_nSquareID = -1;
int g_nLine = -1;
int g_nList = -1;
int g_nSocre = 0;
int g_nLevel = 1;
int timeCounter = 500;
void OnPaint(HDC hDc)//����ʵ��
{   
	char strScore[10] = {0};
	char strLevel[10] = {0};
	//���������DC,DCֻ��һ�����
	HDC hMemDc = CreateCompatibleDC(hDc);
	//����һ��ֽ��������λͼ������ͼ��
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDc,500,600);
	//����ź�ֽ��������
	SelectObject(hMemDc,hBitmapBack);
	PaintSqure(hMemDc);
	ShowSquare2(hMemDc);
	//����  //Դdc
	//ת������Ϊ�ַ���
	itoa(g_nSocre,strScore, 10);
	itoa(g_nLevel,strLevel, 10);
	BitBlt( hDc, 0, 0, 300, 600, hMemDc, 0, 0,SRCCOPY);
	TextOut( hDc, 380, 40,"Score",strlen("Score"));
	TextOut( hDc, 393, 60,strScore,strlen(strScore));
	TextOut( hDc, 380, 120,"Level",strlen("Score"));
	TextOut( hDc, 393, 140,strLevel,strlen(strLevel));
	//�ͷ�DC
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDc);
}

void OnCreate()
{
	srand((unsigned int)time(NULL));//�������ӣ�ֻ��Ҫһ��
	CreateRandSquare();
    CopySquareToBack();
}

void PaintSqure(HDC hMemDc)
{   int i = 0;
	int j = 0;
	HBRUSH hBrushBackNew = CreateSolidBrush(RGB(246,255,204));
	HBRUSH hBrushBackOld;
	HBRUSH hOldBrush;
    HBRUSH hNewBrush;
	hBrushBackOld = SelectObject(hMemDc,hBrushBackNew);
	//���󷽿�
	Rectangle(hMemDc,0,0,300,600);//��һ�����������������壬ǰ���������������Ͻ����꣬�����������������½����꣬ע������Դ��ڵ�����,��������
	hBrushBackNew =  SelectObject(hMemDc,hBrushBackOld);
	DeleteObject;
	//����
	//������
	//ָ��һ������	
	//OnCreate();//�Լ��ӣ���Ҫ��������ʾ
	
    hNewBrush = CreateSolidBrush(RGB(184,0,71));
	hOldBrush = SelectObject(hMemDc,hNewBrush);

	for(i = 0;i < 20;i++)
	{	for(j = 0;j < 10;j++)
		{
			if(g_arrBackGround[i][j] == 1)
			{   //������
				Rectangle(hMemDc,j*30,i*30,j*30+30,i*30+30);			
	
			}

		}
	}
	hNewBrush = SelectObject(hMemDc,hOldBrush);
	DeleteObject;
}

//���������
int CreateRandSquare()
{   int nIndex = rand() % 7;	
	switch(nIndex)//nIndex
	{
		case 0:
			g_arrSquare[0][0] = 1,g_arrSquare[0][1] = 1,g_arrSquare[0][2] = 0,g_arrSquare[0][3] = 0;
			g_arrSquare[1][0] = 0,g_arrSquare[1][1] = 1,g_arrSquare[1][2] = 1,g_arrSquare[1][3] = 0;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 1:
			g_arrSquare[0][0] = 0,g_arrSquare[0][1] = 1,g_arrSquare[0][2] = 1,g_arrSquare[0][3] = 0;
			g_arrSquare[1][0] = 1,g_arrSquare[1][1] = 1,g_arrSquare[1][2] = 0,g_arrSquare[1][3] = 0;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 2:
			g_arrSquare[0][0] = 1,g_arrSquare[0][1] = 0,g_arrSquare[0][2] = 0,g_arrSquare[0][3] = 0;
			g_arrSquare[1][0] = 1,g_arrSquare[1][1] = 1,g_arrSquare[1][2] = 1,g_arrSquare[1][3] = 0;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 3:
			g_arrSquare[0][0] = 0,g_arrSquare[0][1] = 0,g_arrSquare[0][2] = 1,g_arrSquare[0][3] = 0;
			g_arrSquare[1][0] = 1,g_arrSquare[1][1] = 1,g_arrSquare[1][2] = 1,g_arrSquare[1][3] = 0;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 4:
			g_arrSquare[0][0] = 0,g_arrSquare[0][1] = 1,g_arrSquare[0][2] = 0,g_arrSquare[0][3] = 0;
			g_arrSquare[1][0] = 1,g_arrSquare[1][1] = 1,g_arrSquare[1][2] = 1,g_arrSquare[1][3] = 0;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 5:
			g_arrSquare[0][0] = 1,g_arrSquare[0][1] = 1,g_arrSquare[0][2] = 0,g_arrSquare[0][3] = 0;
			g_arrSquare[1][0] = 1,g_arrSquare[1][1] = 1,g_arrSquare[1][2] = 0,g_arrSquare[1][3] = 0;
			break;
		case 6:
			g_arrSquare[0][0] = 1,g_arrSquare[0][1] = 1,g_arrSquare[0][2] = 1,g_arrSquare[0][3] = 1;
			g_arrSquare[1][0] = 0,g_arrSquare[1][1] = 0,g_arrSquare[1][2] = 0,g_arrSquare[1][3] = 0;
			g_nLine = 0;
			g_nList = 4;
			break;
	}
	g_nSquareID = nIndex;
	return nIndex;
}

void CopySquareToBack()
{	
	int i = 0;
	int j = 0;
	for(i = 0;i < 2;i++){
		for(j = 0;j < 4;j++)
		{
			g_arrBackGround[i][j+3] = g_arrSquare[i][j];
		}
	}
}

void OnReturn(HWND hWnd)
{
	//�򿪶�ʱ��
	SetTimer(hWnd,DEF_TIMER1,timeCounter,NULL);
}

//��������
void SquareDown()
{
	int i = 0;
	int j = 0;
	for(i = 19;i >= 0;i--) //�����߼����Ӷȣ����±���
		for( j = 0;j < 10; j++)
			if (g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i+1][j] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
}

//��ʱ����Ӧ����
void OnTimer(HWND hWnd)
{
	int CanSquareDown();
    HDC hDC =  GetDC(hWnd);//�ں˶���Ҫ�˹��ͷ�

	if(CanSquareDown() == 1 && CanSquareDown2() == 1)
	{	
		ToFullLoseSquare();
		SquareDown();
		g_nLine++;
	}
	else
	{
		//�õײ���1���2
	    Change1To2();
		//������
		DestroyOneLineSquare();
		//��Ϸ�����ж�
		if(CanGameOver(hWnd) == 0)
		{
			//����Ӧ�ó���
			KillTimer(hWnd,DEF_TIMER1);
			return 0;
		}
		else
		{
		}
		//���������
		CreateRandSquare();
		//���Ƶ�������
		CopySquareToBack();
	}
	//��ʾ���飬ÿ�ζ�ʱ��ѭ������ʱ��Ҫ��ʾ
	//PaintSqure(hDC);
	OnPaint(hDC);
	//�ͷ�
	ReleaseDC(hWnd,hDC);
	KillTimer(hWnd,DEF_TIMER1);
	SetTimer(hWnd,DEF_TIMER1,timeCounter,NULL);

}

int CanGameOver(HWND hWnd)
{  
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		if(g_arrBackGround[0][i] == 2)
		{
			//��Ϸ����,������ʾ
			MessageBox(hWnd,"Game Over","��ʾ",MB_YESNO);
			return 0;
		}	
	}
	return 1;

}

//����ͣ�������,0���������䣬1��������
int CanSquareDown()
{
	int i = 0;
	for(i = 0;i < 10;i++)
		if(g_arrBackGround[19][i] == 1 )
			return 0;//return �ǽ���������exit���˳�����
    return 1;
}

void Change1To2(){
	int i = 0;
	int j = 0;
	for(i = 0;i < 20 ;i++)
		for(j = 0;j < 10;j++)
			if(g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i][j] = 2;
			}
}

void ShowSquare2(HDC hMemDc)
{
    int i = 0;
	int j = 0;
	HBRUSH hOldBrush;
    HBRUSH hNewBrush = CreateSolidBrush(RGB(115,190,206));
	hOldBrush = SelectObject(hMemDc,hNewBrush);
	for(i = 0;i < 20;i++)
		for(j = 0;j < 20;j++)
			if(g_arrBackGround[i][j] == 2)
			{ //������
				Rectangle(hMemDc,j*30,i*30,j*30+30,i*30+30);
			 
			}
	hNewBrush = SelectObject(hMemDc,hOldBrush); //Ϳ��ɫ
	DeleteObject;
}

//ʹ������ͣ�ڷ�����
int CanSquareDown2(){
	int i = 0;
	int j = 0;
	for(i = 19;i >= 0;i--)
		for(j = 0;j < 10;j++)
			if(g_arrBackGround[i][j] == 1)
				if(g_arrBackGround[i+1][j] == 2)
					return 0;
	return 1;
}

void OnLeft(HWND hWnd)
{

	HDC hDc = GetDC(hWnd);
	if(CanSquareLeft()== 1 && CanSquareLeft2())
	{
	    //��������
		SquareLeft();
		g_nList--;
	    //��ʾ����
	    OnPaint(hDc);
	}
	ReleaseDC(hWnd,hDc);
}

void SquareLeft()
{
	int i = 0;
	int j = 0;
	for(i = 0;i < 20;i++)
		for(j = 0;j <10;j++)
			if(g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i][j-1] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
} 

int CanSquareLeft()
{
	int i = 0;
	for(i = 0;i < 20;i++)
		if(g_arrBackGround[i][0] == 1)
			return 0;
	return 1;
}

int CanSquareLeft2()
{
	int i = 0;
	int j = 0;
	for(i = 0;i <20 ;i++)
		for(j = 0;j < 10;j++)
			if(g_arrBackGround[i][j] == 1)
				if(g_arrBackGround[i][j-1] == 2)
					return 0;
	return 1;
}

void OnRight(HWND hWnd)
{
	HDC hDc = GetDC(hWnd);
	if(CanSquareRight() == 1 &&CanSquareRight2() == 1)
	{
	    //��������
		SquareRight();
		g_nList++;
	    //��ʾ����
		OnPaint(hDc);
	}
	ReleaseDC(hWnd,hDc);//!!ReleaseDc��ӦGetDC,deleteDC��ӦCreateDC
}

void SquareRight()
{
	int i = 0;
	int j = 0;
	for(i = 0;i <20 ;i++)
		for(j = 9;j >= 0;j--)
			if(g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i][j+1] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
}

int CanSquareRight(){
	int i = 0;
	for(i = 0;i < 20; i++)
		if(g_arrBackGround[i][9] == 1)
			return 0;
	return 1;
}

int CanSquareRight2()
{
	int i = 0;
	int j = 0;
	for(i = 0;i < 20;i++)
		for(j = 9;j >= 0;j--)
			if(g_arrBackGround[i][j] == 1)
				if(g_arrBackGround[i][j+1] == 2)
					return 0;
	return 1;
}

void OnDown(HWND hWnd)
{
	OnTimer(hWnd);
}

void OnChangeSquare(HWND hWnd)
{
	HDC hDc = GetDC(hWnd);
	switch(g_nSquareID)//g_nSquareID
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4://��ͨ����
			if(CanSquareChangeShape() == 1)
			{
				ChangeSquare();
			}
			else return;
			break;
		case 5://������
			return;
		case 6://������
			if(CanLineSquareChange() == 1)
			{
			    ChangeLineSquare();
			}
			break;
	}
	OnPaint(hDc);
	ReleaseDC(hWnd,hDc);
}

void ChangeSquare()
{
	char arrSquare[3][3] = {0};
	//�����鸴�Ƴ���
	int i = 0;
	int j = 0;
	int nTemp = 2;

    for(i = 0;i < 3;i++)
		for(j = 0;j <3 ;j++)
		{
			arrSquare[i][j] = g_arrBackGround[g_nLine + i][g_nList + j];
		}
	//���κ��ƻ�ȥ
	for(i = 0;i < 3;i++)
		for(j = 0,nTemp = 2;j <3 ;j++)
		{
			g_arrBackGround[g_nLine + i][g_nList + j] = arrSquare[nTemp][i];
			nTemp--;
		}
}

int CanSquareChangeShape()
{
	int i = 0;
	int j = 0;
	for(i = 0;i < 3;i++)
		for(j = 0; j < 3 ;j++)
			if(g_arrBackGround[g_nLine + i][g_nList + j] == 2)
				return 0;
	if(g_nList < 0)
		g_nList = 0;
	else if(g_nList + 2 > 9)
		g_nList = 7;
	return 1;
}

void ChangeLineSquare()
{
	if(g_arrBackGround[g_nLine][g_nList - 1] == 1)//����
	{       //��0
		    g_arrBackGround[g_nLine][g_nList - 1] = 0;
		    g_arrBackGround[g_nLine][g_nList + 1] = 0;
	        g_arrBackGround[g_nLine][g_nList + 2] = 0;
		if(g_arrBackGround[g_nLine+1][g_nList] == 2 )
		{   //��ֵ
			g_arrBackGround[g_nLine-1][g_nList] = 1;
			g_arrBackGround[g_nLine-2][g_nList] = 1;
		    g_arrBackGround[g_nLine-3][g_nList] = 1;
		}
		else if(g_arrBackGround[g_nLine+2][g_nList] == 2)
		{
			g_arrBackGround[g_nLine+1][g_nList] = 1;
			g_arrBackGround[g_nLine-1][g_nList] = 1;
		    g_arrBackGround[g_nLine-2][g_nList] = 1;
		
		}
		else
		{
			//Ԫ�ظ�ֵ
		    g_arrBackGround[g_nLine-1][g_nList] = 1;
		    g_arrBackGround[g_nLine+1][g_nList] = 1;
	        g_arrBackGround[g_nLine+2][g_nList] = 1;
	    }
	}
	else//����
{       //��0
		    g_arrBackGround[g_nLine-1][g_nList] = 0;
		    g_arrBackGround[g_nLine+1][g_nList] = 0;
	        g_arrBackGround[g_nLine+2][g_nList] = 0;
		if(g_arrBackGround[g_nLine][g_nList+1] == 2 || g_nList == 9)//���Ա��λΪ���ģ������������������ı���
		{
			//Ԫ�ظ�ֵ
		    g_arrBackGround[g_nLine][g_nList - 1] = 1;
		    g_arrBackGround[g_nLine][g_nList - 2] = 1;
	        g_arrBackGround[g_nLine][g_nList - 3] = 1;
			//��Ǹı�
			g_nList = g_nList - 2;
		}
		else if(g_arrBackGround[g_nLine][g_nList+2] == 2|| g_nList == 8)//���Ա��λΪ���ģ�����������һ�����ı���
		{
			//Ԫ�ظ�ֵ
		    g_arrBackGround[g_nLine][g_nList + 1] = 1;
		    g_arrBackGround[g_nLine][g_nList - 1] = 1;
	        g_arrBackGround[g_nLine][g_nList - 2] = 1;
			//��Ǹı�
			g_nList = g_nList - 1;
		}
		else if(g_arrBackGround[g_nLine][g_nList-1] == 2|| g_nList == 0)//���Ա��λΪ���ģ�����������һ�����ı���
		{   
			//Ԫ�ظ�ֵ
			g_arrBackGround[g_nLine][g_nList + 1] = 1;
		    g_arrBackGround[g_nLine][g_nList + 2] = 1;
	        g_arrBackGround[g_nLine][g_nList + 3] = 1;
			//��Ǹı�
			g_nList = g_nList + 1;
		}

	    else
		{
		    //Ԫ�ظ�ֵ
		    g_arrBackGround[g_nLine][g_nList - 1] = 1;
		    g_arrBackGround[g_nLine][g_nList + 1] = 1;
	        g_arrBackGround[g_nLine][g_nList + 2] = 1;
	}
 }
}

int CanLineSquareChange()
{
	int i = 1;
	int j = 1;
	for(i = 1; i < 4;i++)//�Ҳ�
		if(g_arrBackGround[g_nLine][g_nList+i] == 2||g_nList + i > 9)
		{
			break;
		}
	for(j = 1;j < 4;j++ )//���
		if(g_arrBackGround[g_nLine][g_nList-j] == 2||g_nList - j < 0)
		{
			break;
		}
	if((i - 1 + j - 1) < 3)
		return 0;
	return 1;
}

void DestroyOneLineSquare()
{
	int i = 0;
	int j = 0;
	int nTempi = 0;
	int nSum = 0;
	for(i = 19;i >=0;i--)
	{
		for(j = 0;j < 10;j++)
		{
			nSum += g_arrBackGround[i][j];
		}
	    if(nSum == 20)
		{
		    //����һ��,��������
			for(nTempi = i - 1;nTempi >= 0;nTempi--)
			{
				for(j = 0;j < 10;j++)
				{
					g_arrBackGround[nTempi+1][j]=g_arrBackGround[nTempi][j];				
				}	
			}
			//�Ʒ�
			g_nSocre += 100;
			//i�ص������
			i = 20;
			if(g_nSocre % 100 == 0 && (timeCounter >= 50))
			{
				g_nLevel ++;
				timeCounter -=200;
			}
		}
		nSum = 0;//��nSumΪ0
	}
}

void ToFullLoseSquare()
{
	if(g_arrBackGround[g_nLine][g_nList - 1] != 1 && g_nSquareID == 6 )
	{
		if(g_arrBackGround[g_nLine-1][g_nList] == 0)
			g_arrBackGround[g_nLine-1][g_nList] = 1;
	}
}