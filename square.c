//#include <windows.h>
#include "resource.h"
#include "elshead.h"
//�ص������ĺ�������
LRESULT CALLBACK PELuosi(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
void OnPaint(HDC hDc);
//WINAPI:����Լ��,��Ҫ�ǲ�����ջ˳�����ջ�ռ��������
//����1--�����һ���������ڵ�Ψһ��ʶ
//����2--��ͬʱ����������ʱ��ǰһ�����ڵľ��
//����3--ָ�����͸�Ӧ�ó���������в���
//����4--ָ�����ڵ���ʾ��ʽ�����أ������С��ʾ��Ĭ��Ϊ1����Ӧһ����SW_SHOWNORMAL ��Ϊ������ʾ(show windows normal)
int	WINAPI WinMain(HINSTANCE hinstance,HINSTANCE hPrevinstance,LPTSTR lpCmdLine,int nCmdShow){
	//��ʼ��������
    //WND:WINDOWS CLASS:�� EX:EXTRA ��չ ����һ����WNDCLASSEX
	MSG msg;
	HWND hWnd;
	WNDCLASSEX wc;//���ϰ汾WNDCLASS��һ����չ
	wc.cbClsExtra = 0;//�����ڴ�����β����һ�����ռ䣬����ʱ��Ϊ0
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_INACTIVECAPTION;//hbr--hbrush��д��������ɫ����������ϲ����ǳ��ɫ
	wc.hCursor = LoadCursor(hinstance,MAKEINTRESOURCE(101));//����ڲ�ͬλ�õ���ʾЧ��
	wc.hIcon = LoadCursor(NULL,IDC_HAND);//״̬��Сͼ��
	wc.hIconSm = LoadCursor(hinstance,MAKEINTRESOURCE(101));//�������Ͻǵ���ͼ����ʾ
	wc.hInstance = hinstance;//��ǰ���ڵ�ʵ���������ϵͳ����
	wc.lpfnWndProc = PELuosi;//�ص������ĺ�����ַ����������
	wc.lpszClassName = "els";//�������Ψһ����,���ֲ�Ҫ�ظ�--��Ҫ���ݸ�����ϵͳ
	wc.lpszMenuName = NULL;//���ڲ˵�
	wc.style = CS_HREDRAW | CS_VREDRAW;//���ڷ��:�����Ǵ�ֱˢ�º�ˮƽˢ��
	//12����Ա
	//ע�ᴰ�ڶ���
	//ATOM//unsigned short
	if(0 == RegisterClassEx(&wc))
	{
		int a = GetLastError();//�����ˣ���֪����ʲô����
		return 0;
		};
	
	 //��������
	hWnd = CreateWindowEx(WS_EX_TOPMOST,"els","�����ʺ���",WS_OVERLAPPEDWINDOW,100,100,500,645,NULL,NULL,hinstance,NULL);//WS_OVERLAPPEDWINDOW�Ǵ��ڷ��
	//����������֣��������ָ��˿�
	//���������Ͻ����꣬100���أ�100����
	//���ڴ�С����ȣ��߶ȣ�
	//��lp��ָ������
	if (NULL == hWnd) //���ھ�� ���ڵ�Ψһ��ʶ
	{   
		int b = GetLastError();
		return 0;
		}
	//��ʾ����
	ShowWindow(hWnd,SW_SHOWNORMAL);//SW_SHOWNORMAL ��ʾ���,nCmdShowҲһ��������������¶���1
	//������ʾ����0��������ʾ���ط�0,������ɹ�ʧ��//����
	 
	//��Ϣѭ��,WINDOWS�ǻ�����Ϣ����Ӧ��,��Ϣ���У��Ƚ��ȳ�,��Ϣ��һ���ṹ��,����ΪMSG
	while(GetMessage(&msg,NULL,0,0))
	{
		//
		TranslateMessage(&msg);//������Ϣ:�����ź�ת��Ϊ�ַ���Ϣ  'a'
		//
		DispatchMessage(&msg);//�ַ���Ϣ ��Ϣ���ͣ���׼��Ϣ��������Ϣ��֪ͨ��Ϣ���Զ�����Ϣ
	    //long result �������õĽ��������Ϊlong
	};	//��Ϣ��ID unsigned int
	return 0;
	system("pause");
};
LRESULT CALLBACK PELuosi(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{   PAINTSTRUCT pt;
    HDC hDc;//�����Ͽɲ�������ı�ʶ���豸����������Ǵ����е�һ��Ԫ�أ����ִ��ھ����
	switch(msg)
	{
		case WM_CREATE://���ڴ�������ֻ����һ��,һ����Ϊ��ʼ����
			//GetLastError();//ע�⣡����Ϊ�ձ�ǩ������ʱ����ϵͳ�Ż����ͻ�������һ��
			OnCreate();
			//break;
		case WM_PAINT:
			hDc = BeginPaint(hWnd,&pt);//�������ϵ�����,�õ����ھ��
			//Rectangle(hDc,0,0,300,600);//hDc�����������壬ǰ���������������Ͻ����꣬�����������������½����꣬ע������Դ��ڵ�����,��������
			//Rectangle(hDc,30,30,60,60);
			OnPaint(hDc);//����ɶ���
			EndPaint(hWnd,&pt);//�ͷŴ��ھ��
			break;
		
		case WM_KEYDOWN:
			switch(wParam)
			{ 
				case VK_RETURN:	
				OnReturn(hWnd);
				break;		
				case VK_LEFT:
				//����
				OnLeft(hWnd);
				break;
				case VK_RIGHT:
				//����
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
			PostQuitMessage(0); //post���� quit �˳� message ��Ϣ WM_CLOSER ����һ������Ϣ��WM_DESTROY ���ٴ���,WM_QUIT ��getmessage���գ��˳�ѭ���������˳�
			break;


	}
	//���ڹرմ���ʱ�������˳�
	return DefWindowProc(hWnd,msg,wParam,lParam);
}//hWndֻ����һ�����ڣ�NULLȫ���Դ���,��Ϣ���������֣���ϢID����0,0��Ϊ��Ϣ��Χʱ������Ϣ������ȡ��
