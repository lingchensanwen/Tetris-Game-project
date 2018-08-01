//#include <windows.h>
#include "resource.h"
#include "elshead.h"
//回调函数的函数声明
LRESULT CALLBACK PELuosi(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
void OnPaint(HDC hDc);
//WINAPI:调用约定,主要是参数入栈顺序，这个栈空间的清理者
//参数1--句柄：一个数，窗口的唯一标识
//参数2--（同时打开两个窗口时）前一个窗口的句柄
//参数3--指定传送给应用程序的命令行参数
//参数4--指定窗口的显示方式，隐藏，最大，最小显示，默认为1，对应一个宏SW_SHOWNORMAL ，为正常显示(show windows normal)
int	WINAPI WinMain(HINSTANCE hinstance,HINSTANCE hPrevinstance,LPTSTR lpCmdLine,int nCmdShow){
	//初始化窗口类
    //WND:WINDOWS CLASS:类 EX:EXTRA 拓展 合在一起是WNDCLASSEX
	MSG msg;
	HWND hWnd;
	WNDCLASSEX wc;//是老版本WNDCLASS的一个拓展
	wc.cbClsExtra = 0;//紧跟在窗口类尾部的一块额外空间，不用时设为0
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_INACTIVECAPTION;//hbr--hbrush缩写，背景颜色，这里是我喜欢的浅蓝色
	wc.hCursor = LoadCursor(hinstance,MAKEINTRESOURCE(101));//光标在不同位置的显示效果
	wc.hIcon = LoadCursor(NULL,IDC_HAND);//状态栏小图标
	wc.hIconSm = LoadCursor(hinstance,MAKEINTRESOURCE(101));//窗口右上角的左图标显示
	wc.hInstance = hinstance;//当前窗口的实例句柄，由系统传递
	wc.lpfnWndProc = PELuosi;//回掉函数的函数地址（函数名）
	wc.lpszClassName = "els";//窗口类的唯一名字,名字不要重复--需要传递给操作系统
	wc.lpszMenuName = NULL;//窗口菜单
	wc.style = CS_HREDRAW | CS_VREDRAW;//窗口风格:这里是垂直刷新和水平刷新
	//12个成员
	//注册窗口对象
	//ATOM//unsigned short
	if(0 == RegisterClassEx(&wc))
	{
		int a = GetLastError();//出错了，不知道是什么错误
		return 0;
		};
	
	 //创建窗口
	hWnd = CreateWindowEx(WS_EX_TOPMOST,"els","三问问盒子",WS_OVERLAPPEDWINDOW,100,100,500,645,NULL,NULL,hinstance,NULL);//WS_OVERLAPPEDWINDOW是窗口风格
	//窗口类的名字，窗口名字给人看
	//到桌面左上角坐标，100像素，100像素
	//窗口大小（宽度，高度）
	//带lp是指针类型
	if (NULL == hWnd) //窗口句柄 窗口的唯一标识
	{   
		int b = GetLastError();
		return 0;
		}
	//显示窗口
	ShowWindow(hWnd,SW_SHOWNORMAL);//SW_SHOWNORMAL 显示风格,nCmdShow也一样，在这种情况下都是1
	//隐藏显示返回0，正常显示返回非0,不代表成功失败//测试
	 
	//消息循环,WINDOWS是基于消息而响应的,消息队列：先进先出,消息是一个结构体,名字为MSG
	while(GetMessage(&msg,NULL,0,0))
	{
		//
		TranslateMessage(&msg);//翻译消息:将电信号转换为字符消息  'a'
		//
		DispatchMessage(&msg);//分发消息 消息类型：标准消息，命令消息，通知消息，自定义消息
	    //long result 函数调用的结果，类型为long
	};	//消息的ID unsigned int
	return 0;
	system("pause");
};
LRESULT CALLBACK PELuosi(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{   PAINTSTRUCT pt;
    HDC hDc;//窗口上可操作区域的标识，设备环境句柄，是窗口中的一个元素（区分窗口句柄）
	switch(msg)
	{
		case WM_CREATE://窗口创建初期只产生一次,一般作为初始化。
			//GetLastError();//注意！！若为空标签，编译时候有系统优化，就会跳过这一段
			OnCreate();
			//break;
		case WM_PAINT:
			hDc = BeginPaint(hWnd,&pt);//画窗口上的内容,得到窗口句柄
			//Rectangle(hDc,0,0,300,600);//hDc可以视作画板，前两个参数代表左上角坐标，后两个参数代表右下角坐标，注意是相对窗口的坐标,不是桌面
			//Rectangle(hDc,30,30,60,60);
			OnPaint(hDc);//代码可读性
			EndPaint(hWnd,&pt);//释放窗口句柄
			break;
		
		case WM_KEYDOWN:
			switch(wParam)
			{ 
				case VK_RETURN:	
				OnReturn(hWnd);
				break;		
				case VK_LEFT:
				//左移
				OnLeft(hWnd);
				break;
				case VK_RIGHT:
				//右移
				OnRight(hWnd);
				break;
				case VK_UP:
				OnChangeSquare(hWnd);
				break;
				case VK_DOWN:
				OnDown(hWnd);
				break;	
			}
		case WM_TIMER:
			OnTimer(hWnd);
			break;
		case WM_DESTROY:	//window message destroy
			KillTimer(hWnd,DEF_TIMER1);
			PostQuitMessage(0); //post传递 quit 退出 message 消息 WM_CLOSER 消除一部分消息，WM_DESTROY 销毁窗口,WM_QUIT 被getmessage接收，退出循环，真正退出
			break;


	}
	//用于关闭窗口时候真正退出
	return DefWindowProc(hWnd,msg,wParam,lParam);
}//hWnd只处理一个窗口，NULL全可以处理,消息用数字区分（消息ID），0,0作为消息范围时所以消息都可以取到
