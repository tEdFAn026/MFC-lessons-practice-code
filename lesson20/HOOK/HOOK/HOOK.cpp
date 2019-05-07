#include <windows.h>

HHOOK g_hMouseHook = NULL;
HHOOK g_hKeyBoardHook = NULL;

#pragma data_seg("Mysec")
HWND g_hWnd = NULL;
#pragma data_seg()

#pragma comment(linker,"/section:Mysec,RWS")
//HINSTANCE g_hInst;
//BOOL WINAPI DllMain(
//	_In_ HINSTANCE hinstDLL, // ָ������ľ��
//	_In_ DWORD fdwReason, // ����ԭ��
//	_In_ LPVOID lpvReserved // ��ʽ���غ���ʽ����
//) {
//	g_hInst = hinstDLL;
//}
//// ������������MSDN

//LRESULT CALLBACK MyMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
//	return 1;
//}

LRESULT CALLBACK MyKeyBoardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (VK_F2 == wParam) {
		::SendMessage(g_hWnd, WM_CLOSE, 0, 0);
		//UnhookWindowsHookEx(g_hMouseHook);
		UnhookWindowsHookEx(g_hKeyBoardHook);
	}
	return 1;
}

void SetHook(HWND hWnd) {
	g_hWnd = hWnd;
	//g_hMouseHook = SetWindowsHookEx(WH_MOUSE, MyMouseProc, GetModuleHandle(L"HOOK"), 0);
	g_hKeyBoardHook = SetWindowsHookEx(WH_KEYBOARD, MyKeyBoardProc, GetModuleHandle(L"HOOK"), 0);
}