#include <windows.h>

int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPWSTR ipszCmdLine,int nCmdShow)
{
	//MessageBox(NULL,L"Message",L"Hello",MB_OK);

	HWND hwnd=CreateWindowEx(0,L"EDIT",L"MyEditWindows",WS_OVERLAPPEDWINDOW,100,100,500,400,NULL,NULL, hInstance,NULL);
	
	ShowWindow(hwnd,SW_SHOW);
	MSG msg = { 0 };

	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}