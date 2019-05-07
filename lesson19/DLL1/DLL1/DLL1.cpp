#define DLL1_API extern "C" _declspec(dllexport)
#include "DLL1.h"
#include <windows.h>
#include <stdio.h>

int _stdcall add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

//void Point::output(int x, int y)
//{
//	HWND hWnd = GetForegroundWindow();
//	HDC hDc = GetDC(hWnd);
//	wchar_t buf[32];
//	memset(buf, 0, sizeof(buf));
//	swprintf_s(buf, L"x=%d,y=%d", x, y);
//	MessageBox(hWnd, buf, L"output", 0);
//	//TextOut(hDc, 0, 0, buf, wcslen(buf));
//}
//
//void Point::test()
//{
//}
