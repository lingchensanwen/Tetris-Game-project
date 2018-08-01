#include "elshead.h"
//背景数组
char g_arrBackGround[20][10] = {0};//int 200 * 4 800 200 节约空间
char g_arrSquare[2][4] = {0};
int g_nSquareID = -1;
int g_nLine = -1;
int g_nList = -1;
int g_nSocre = 0;
int g_nLevel = 1;
int timeCounter = 500;
void OnPaint(HDC hDc)//函数实现
{   
	char strScore[10] = {0};
	char strLevel[10] = {0};
	//创造兼容性DC,DC只是一个编号
	HDC hMemDc = CreateCompatibleDC(hDc);
	//创造一张纸，兼容性位图（像素图）
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDc,500,600);
	//将编号和纸关联起来
	SelectObject(hMemDc,hBitmapBack);
	PaintSqure(hMemDc);
	ShowSquare2(hMemDc);
	//传递  //源dc
	//转换整数为字符串
	itoa(g_nSocre,strScore, 10);
	itoa(g_nLevel,strLevel, 10);
	BitBlt( hDc, 0, 0, 300, 600, hMemDc, 0, 0,SRCCOPY);
	TextOut( hDc, 380, 40,"Score",strlen("Score"));
	TextOut( hDc, 393, 60,strScore,strlen(strScore));
	TextOut( hDc, 380, 120,"Level",strlen("Score"));
	TextOut( hDc, 393, 140,strLevel,strlen(strLevel));
	//释放DC
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDc);
}

void OnCreate()
{
	srand((unsigned int)time(NULL));//种下种子，只需要一次
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
	//画大方块
	Rectangle(hMemDc,0,0,300,600);//第一个参数可以视作画板，前两个参数代表左上角坐标，后两个参数代表右下角坐标，注意是相对窗口的坐标,不是桌面
	hBrushBackNew =  SelectObject(hMemDc,hBrushBackOld);
	DeleteObject;
	//遍历
	//画方块
	//指定一个方块	
	//OnCreate();//自己加，需要！！来显示
	
    hNewBrush = CreateSolidBrush(RGB(184,0,71));
	hOldBrush = SelectObject(hMemDc,hNewBrush);

	for(i = 0;i < 20;i++)
	{	for(j = 0;j < 10;j++)
		{
			if(g_arrBackGround[i][j] == 1)
			{   //画方块
				Rectangle(hMemDc,j*30,i*30,j*30+30,i*30+30);			
	
			}

		}
	}
	hNewBrush = SelectObject(hMemDc,hOldBrush);
	DeleteObject;
}

//创建随机块
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
	//打开定时器
	SetTimer(hWnd,DEF_TIMER1,timeCounter,NULL);
}

//方块下落
void SquareDown()
{
	int i = 0;
	int j = 0;
	for(i = 19;i >= 0;i--) //减少逻辑复杂度，从下遍历
		for( j = 0;j < 10; j++)
			if (g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i+1][j] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
}

//定时器响应函数
void OnTimer(HWND hWnd)
{
	int CanSquareDown();
    HDC hDC =  GetDC(hWnd);//内核对象，要人工释放

	if(CanSquareDown() == 1 && CanSquareDown2() == 1)
	{	
		ToFullLoseSquare();
		SquareDown();
		g_nLine++;
	}
	else
	{
		//让底部的1变成2
	    Change1To2();
		//消除行
		DestroyOneLineSquare();
		//游戏结束判断
		if(CanGameOver(hWnd) == 0)
		{
			//结束应用程序
			KillTimer(hWnd,DEF_TIMER1);
			return 0;
		}
		else
		{
		}
		//产生随机块
		CreateRandSquare();
		//复制到背景上
		CopySquareToBack();
	}
	//显示方块，每次定时器循环运作时候都要显示
	//PaintSqure(hDC);
	OnPaint(hDC);
	//释放
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
			//游戏结束,弹出提示
			MessageBox(hWnd,"Game Over","提示",MB_YESNO);
			return 0;
		}	
	}
	return 1;

}

//方块停在最底下,0不可以下落，1可以下落
int CanSquareDown()
{
	int i = 0;
	for(i = 0;i < 10;i++)
		if(g_arrBackGround[19][i] == 1 )
			return 0;//return 是结束函数，exit是退出程序
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
			{ //画方块
				Rectangle(hMemDc,j*30,i*30,j*30+30,i*30+30);
			 
			}
	hNewBrush = SelectObject(hMemDc,hOldBrush); //涂颜色
	DeleteObject;
}

//使方块能停在方块上
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
	    //方块左移
		SquareLeft();
		g_nList--;
	    //显示方块
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
	    //方块右移
		SquareRight();
		g_nList++;
	    //显示方块
		OnPaint(hDc);
	}
	ReleaseDC(hWnd,hDc);//!!ReleaseDc对应GetDC,deleteDC对应CreateDC
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
		case 4://普通变形
			if(CanSquareChangeShape() == 1)
			{
				ChangeSquare();
			}
			else return;
			break;
		case 5://正方形
			return;
		case 6://长条形
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
	//背景块复制出来
	int i = 0;
	int j = 0;
	int nTemp = 2;

    for(i = 0;i < 3;i++)
		for(j = 0;j <3 ;j++)
		{
			arrSquare[i][j] = g_arrBackGround[g_nLine + i][g_nList + j];
		}
	//变形后复制回去
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
	if(g_arrBackGround[g_nLine][g_nList - 1] == 1)//横着
	{       //清0
		    g_arrBackGround[g_nLine][g_nList - 1] = 0;
		    g_arrBackGround[g_nLine][g_nList + 1] = 0;
	        g_arrBackGround[g_nLine][g_nList + 2] = 0;
		if(g_arrBackGround[g_nLine+1][g_nList] == 2 )
		{   //赋值
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
			//元素赋值
		    g_arrBackGround[g_nLine-1][g_nList] = 1;
		    g_arrBackGround[g_nLine+1][g_nList] = 1;
	        g_arrBackGround[g_nLine+2][g_nList] = 1;
	    }
	}
	else//竖着
{       //清0
		    g_arrBackGround[g_nLine-1][g_nList] = 0;
		    g_arrBackGround[g_nLine+1][g_nList] = 0;
	        g_arrBackGround[g_nLine+2][g_nList] = 0;
		if(g_arrBackGround[g_nLine][g_nList+1] == 2 || g_nList == 9)//（以标记位为中心）向左依次推两个，改变标记
		{
			//元素赋值
		    g_arrBackGround[g_nLine][g_nList - 1] = 1;
		    g_arrBackGround[g_nLine][g_nList - 2] = 1;
	        g_arrBackGround[g_nLine][g_nList - 3] = 1;
			//标记改变
			g_nList = g_nList - 2;
		}
		else if(g_arrBackGround[g_nLine][g_nList+2] == 2|| g_nList == 8)//（以标记位为中心）向左依次推一个，改变标记
		{
			//元素赋值
		    g_arrBackGround[g_nLine][g_nList + 1] = 1;
		    g_arrBackGround[g_nLine][g_nList - 1] = 1;
	        g_arrBackGround[g_nLine][g_nList - 2] = 1;
			//标记改变
			g_nList = g_nList - 1;
		}
		else if(g_arrBackGround[g_nLine][g_nList-1] == 2|| g_nList == 0)//（以标记位为中心）向右依次推一个，改变标记
		{   
			//元素赋值
			g_arrBackGround[g_nLine][g_nList + 1] = 1;
		    g_arrBackGround[g_nLine][g_nList + 2] = 1;
	        g_arrBackGround[g_nLine][g_nList + 3] = 1;
			//标记改变
			g_nList = g_nList + 1;
		}

	    else
		{
		    //元素赋值
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
	for(i = 1; i < 4;i++)//右侧
		if(g_arrBackGround[g_nLine][g_nList+i] == 2||g_nList + i > 9)
		{
			break;
		}
	for(j = 1;j < 4;j++ )//左侧
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
		    //消除一行,逐行下移
			for(nTempi = i - 1;nTempi >= 0;nTempi--)
			{
				for(j = 0;j < 10;j++)
				{
					g_arrBackGround[nTempi+1][j]=g_arrBackGround[nTempi][j];				
				}	
			}
			//计分
			g_nSocre += 100;
			//i回到最底下
			i = 20;
			if(g_nSocre % 100 == 0 && (timeCounter >= 50))
			{
				g_nLevel ++;
				timeCounter -=200;
			}
		}
		nSum = 0;//清nSum为0
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