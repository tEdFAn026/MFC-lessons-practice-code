#include <windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI Fun1Proc(LPVOID lpParameter);
DWORD WINAPI Fun2Proc(LPVOID lpParameter);

int index = 0;
int tickets = 100;
HANDLE hMutex;
void main() {
	//hMutex = CreateMutex(NULL, FALSE, NULL);
	hMutex = CreateMutex(NULL, TRUE, "tickets");
	if (hMutex) {
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			cout << "only instance can run!" << endl;
			return;
		}
	}
	
	WaitForSingleObject(hMutex, INFINITE);
	ReleaseMutex(hMutex);
	ReleaseMutex(hMutex);

	HANDLE hThread1;
	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	CloseHandle(hThread1);

	HANDLE hThread2;
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	CloseHandle(hThread2);

	Sleep(4000);
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter) {

	while (true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0) {
			Sleep(1);
			printf("Fun1Proc sell ticket:%d\n", tickets--);
		}
		else 
			break;
		ReleaseMutex(hMutex);
	}
	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter) {

	while (true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0) {
			Sleep(1);
			printf("Fun2Proc sell ticket:%d\n", tickets--);
		}
		else
			break;
		ReleaseMutex(hMutex);
	}
	return 0;
}