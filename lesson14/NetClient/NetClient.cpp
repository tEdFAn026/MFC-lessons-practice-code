#define WIN32_LEAN_AND_MEAN
//#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")


int __cdecl main()
{

	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		/* Tell the user that we could not find a usable */
		/* Winsock DLL.                                  */
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}

	/* Confirm that the WinSock DLL supports 2.2.*/
	/* Note that if the DLL supports versions greater    */
	/* than 2.2 in addition to 2.2, it will still return */
	/* 2.2 in wVersion since that is the version we      */
	/* requested.                                        */

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		printf("Could not find a usable version of Winsock.dll\n");
		WSACleanup();
		return 1;
	}
	else
		printf("The Winsock 2.2 dll was found okay\n");


	/* The Winsock DLL is acceptable. Proceed to use it. */

	/* Add network programming using Winsock here */

	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN addrSrv;
	inet_pton(AF_INET, "127.0.0.1", &addrSrv.sin_addr);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	char recvBuf[128];
	char sendBuf[128];
	char tempBuf[128];

	//SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	while (true)
	{
		printf("please input:");
		gets_s(sendBuf);
		sendto(sockClient, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

		recvfrom(sockClient, recvBuf, 128, 0, (SOCKADDR*)&addrSrv, &len);
		if ('q' == recvBuf[0]) {
			sendto(sockClient, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrSrv , len);
			printf("Chat end\n");
			break;
		}

		char clientIPBuf[32];
		inet_ntop(AF_INET, &addrSrv.sin_addr, (PSTR)&clientIPBuf, 32);

		sprintf_s(tempBuf, "%s say:%s", clientIPBuf, recvBuf);
		printf("%s\n", tempBuf);
	}


	closesocket(sockClient);

	/* then call WSACleanup when done using the Winsock dll */

	WSACleanup();

}