#include <windows.h>
#include <iostream>
#define MUTEX
#define EVENT
using namespace std;

DWORD WINAPI Fun1Proc(LPVOID lpParameter);
DWORD WINAPI Fun2Proc(LPVOID lpParameter);

int tickets = 100;
HANDLE g_hEvent;
HANDLE g_hMutex;
void main() {

	//g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	g_hEvent = CreateEvent(NULL, FALSE, FALSE, L"tickets");
	SetEvent(g_hEvent);

	if (g_hEvent) {
		if (ERROR_ALREADY_EXISTS == GetLastError()) {
			cout << "only instance can run!" << endl;
			return;
		}
	}

	HANDLE hThread1;
	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	CloseHandle(hThread1);

	HANDLE hThread2;
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	CloseHandle(hThread2);

	Sleep(4000);
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter) {

	while (true) {
		WaitForSingleObject(g_hEvent, INFINITE);
		if (tickets > 0) {
			Sleep(1);
			printf("Fun1Proc sell ticket:%d\n", tickets--);
		}
		else
			break;
		SetEvent(g_hEvent);
	}
	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter) {

	while (true) {
		WaitForSingleObject(g_hEvent, INFINITE);
		if (tickets > 0) {
			Sleep(1);
			printf("Fun2Proc sell ticket:%d\n", tickets--);
		}
		else
			break;
		SetEvent(g_hEvent);
	}
	return 0;
}