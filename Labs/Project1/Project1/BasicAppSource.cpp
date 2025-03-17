#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwand, UINT nMsg, WPARAM wParm, LPARAM lParam);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR ipszCmdLine, int nCmdShow)
{
	//MessageBox(NULL,L"Message",L"Hello",MB_OK);

	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.hInstance = hInstance;
	wc.lpszClassName = L"MyWndClass";
	wc.lpfnWndProc = WindowProc;

	RegisterClassEx(&wc);

	HWND hwnd = CreateWindowEx(0, L"EDIT", L"MyEditWindows", WS_OVERLAPPEDWINDOW, 100, 100, 500, 400, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, SW_SHOW);
	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT nMsg, WPARAM wParm, LPARAM lParam) {
	switch (nMsg)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		case WM_PAINT: {
			break;
		}

		case WM_COMMAND: {
			break;
		}
	}
	return DefWindowProc(hwnd, nMsg, wParm, lParam);
}