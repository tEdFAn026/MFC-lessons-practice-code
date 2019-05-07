#include <windows.h>
#include <iostream>
#define MUTEX
#define EVENT
using namespace std;

DWORD WINAPI Fun1Proc(LPVOID lpParameter);
DWORD WINAPI Fun2Proc(LPVOID lpParameter);

int tickets = 100;
CRITICAL_SECTION g_csA;
CRITICAL_SECTION g_csB;
void main() {

	InitializeCriticalSection(&g_csA);
	InitializeCriticalSection(&g_csB);

	HANDLE hThread1;
	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	CloseHandle(hThread1);

	HANDLE hThread2;
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	CloseHandle(hThread2);

	Sleep(4000);

	DeleteCriticalSection(&g_csA);
	DeleteCriticalSection(&g_csB);
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter) {

	while (true) {
		EnterCriticalSection(&g_csA);
		Sleep(1);
		EnterCriticalSection(&g_csB);
		if (tickets > 0) {
			Sleep(1);
			printf("Fun1Proc sell ticket:%d\n", tickets--);
		}
		else
			break;
		LeaveCriticalSection(&g_csB);
		LeaveCriticalSection(&g_csA);
	}
	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter) {

	while (true) {
		EnterCriticalSection(&g_csB);
		Sleep(1);
		EnterCriticalSection(&g_csA);
		if (tickets > 0) {
			Sleep(1);
			printf("Fun2Proc sell ticket:%d\n", tickets--);
		}
		else
			break;
		LeaveCriticalSection(&g_csA);
		LeaveCriticalSection(&g_csB);
	}
	return 0;
}