#include <Windows.h>
#include <winsock.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	cout << "UDP CLient..." << endl;
	

	WSADATA WinSockData;
	int iWsaStartup;
	int iWsaCleanup;

	SOCKET UDPSocketClient;
	struct sockaddr_in UDPServer;

	char Buffer[512];

	char BufferFrom[512];
	int iBufferFromLen = strlen(BufferFrom) + 1;
	char iSendto;
	char iReceiveFrom;
	int iBufferLen = strlen(Buffer) + 1;
	int iUDPServerLen = sizeof(UDPServer);
	int iCloseSocket;
	int ok = 0;
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSockData);
	if (iWsaStartup != 0)
	{
		cout << "Failed to create!";
	}
	cout << "WSAStartUp Succes!"<<endl;

	UDPServer.sin_family = AF_INET;
	UDPServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	UDPServer.sin_port = htons(8008);
	UDPSocketClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (UDPSocketClient == INVALID_SOCKET)
	{
		cout << "Socket Creation Failed!" << endl;
	}
	cout << "Socket Creation Succes" << endl;

	
	
	

	printf("Comanda : ");
	gets_s(Buffer);

	printf("Comanda ta: %s \n", Buffer);


	iSendto = sendto(UDPSocketClient, Buffer, iBufferLen, MSG_DONTROUTE, (SOCKADDR*)&UDPServer, sizeof(UDPServer));
	if (iSendto == SOCKET_ERROR)
	{		
	}
	else{
	printf("Am trimis: %s \n", Buffer);}
			
	
	iCloseSocket = closesocket(UDPSocketClient);

	if (iCloseSocket == SOCKET_ERROR)
	{
		cout << "Close failed!" << endl;
	}
	cout << "Close Succes!" << endl;

	iWsaCleanup = WSACleanup();
	if (iWsaCleanup == SOCKET_ERROR)
	{
		cout << "Cleanup failed!" << endl;
	}
	cout << "Cleanup Succes!" << endl;

	system("PAUSE");
	return 0;
}