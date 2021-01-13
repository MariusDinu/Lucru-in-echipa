#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <winsock.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")

using namespace std;
DWORD32 countStars = 0;//variabila globala pentru a retine nivelurile la arbore


string creareFisier(string numeFisier) { 
	HANDLE hFile = CreateFile(
		numeFisier.c_str(),     
		GENERIC_WRITE,          
		FILE_SHARE_READ,        
		NULL,                   
		CREATE_NEW,             
		FILE_ATTRIBUTE_NORMAL,  
		NULL);                  

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return "Error";
	}
	return "Good";
}
string appendFisier(string loc,char *desc) {
	string text = desc;
	std::wstring pathStr = std::wstring(loc.begin(), loc.end());
	LPCWSTR path = pathStr.c_str();
	HANDLE hFile;
	DWORD dwBytesToWrite = strlen(text.c_str());
	DWORD dwBytesWritten;
	BOOL bErrorFlag = FALSE;

	hFile = CreateFileW(path,  // name of the write
		FILE_APPEND_DATA,          // open for appending
		FILE_SHARE_READ,           // share for reading only
		NULL,                      // default security
		OPEN_ALWAYS,               // open existing file or create new file 
		FILE_ATTRIBUTE_NORMAL,     // normal file
		NULL);                     // no attr. template

	if (hFile == INVALID_HANDLE_VALUE)
	{	
		printf("Nu se poate deschide fisierul: \"%s\" .\n", path);
		return "Error";
	}

	while (dwBytesToWrite > 0)
	{
		bErrorFlag = WriteFile(
			hFile,              // open file handle
			text.c_str(),               // start of data to write
			dwBytesToWrite,     // number of bytes to write
			&dwBytesWritten,    // number of bytes that were written
			NULL);              // no overlapped structure

		if (!bErrorFlag)
		{
			
			printf("Nu se poate scrie in acest fisier.\n");
			break;
		}


		text+= dwBytesWritten;
		dwBytesToWrite -= dwBytesWritten;
	}

	CloseHandle(hFile);
	return "Good";
}
string deleteFisier(string path) {
	DWORD val;
	val = DeleteFile(path.c_str());
	if (val == 1) { return "Good"; } return "Error";
}

string createKey(string key,string path){

	printf("key: %s \n",key.c_str());
	printf("path: %s \n", path.c_str());
    HKEY hKey;
    HKEY local=NULL;
   
	if (key.compare("HKEY_CURRENT_CONFIG") == 0)  local = HKEY_CURRENT_CONFIG;
	if (key.compare("HKEY_CURRENT_USER") == 0)  local = HKEY_CURRENT_USER;
	if (key.compare("HKEY_LOCAL_MACHINE") == 0)  local = HKEY_LOCAL_MACHINE;
	if (key.compare("HKEY_USERS") == 0)  local = HKEY_USERS;
	if (key.compare("HKEY_CLASSES_ROOT") == 0)  local = HKEY_CLASSES_ROOT;
   
	LONG openRes = RegCreateKeyEx(
		local,
		path.c_str(),
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&hKey,
		NULL);
	if (openRes != ERROR_SUCCESS) { return "Error"; }
	return "Good";
}
string deleteKey(string key,string path) {
	printf("key: %s \n", key.c_str());
	printf("path: %s \n", path.c_str());
	HKEY hKey;
	HKEY local = NULL;

	if (key.compare("HKEY_CURRENT_CONFIG") == 0)  local = HKEY_CURRENT_CONFIG;
	if (key.compare("HKEY_CURRENT_USER") == 0)  local = HKEY_CURRENT_USER;
	if (key.compare("HKEY_LOCAL_MACHINE") == 0)  local = HKEY_LOCAL_MACHINE;
	if (key.compare("HKEY_USERS") == 0)  local = HKEY_USERS;
	if (key.compare("HKEY_CLASSES_ROOT") == 0)  local = HKEY_CLASSES_ROOT;
	LONG lReturn = RegDeleteKey(local, path.c_str());
	return "Good";
}

string run(string path) {
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);

	if (!CreateProcess(path.c_str(), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		return "Error";
	}
	else {
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		return "Good";
	}
}

string download(string path,string numeFisier) {
	HRESULT hr;
	bool ok = true;
	LPCTSTR Url = path.c_str();
	string File = "C:\\Users\\mariu\\Desktop\\test\\"+numeFisier;
	hr = URLDownloadToFile(0, Url, File.c_str(), 0, 0);
	switch (hr)
	{
	case S_OK:
		printf( "Successful download\n");
		break;
	case E_OUTOFMEMORY:
		printf( "Out of memory error\n"); ok = false;
		break;
	case INET_E_DOWNLOAD_FAILURE:
		printf( "Cannot access server data\n"); ok = false;
		break;
	default:
		printf( "Unknown error\n"); ok = false;
		break;
	}
	
	if(ok==false)
	return "Error";
	return "Good";
}

string list(const char *sDir) { 
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	char sPath[2048];
	sprintf(sPath, "%s\\*.*", sDir);

	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		printf("Nu s-a gasit path-ul: [%s]\n", sDir);
		return "Error";
	}
	do
	{
		if (strcmp(fdFile.cFileName, ".") != 0
			&& strcmp(fdFile.cFileName, "..") != 0)
		{
			sprintf(sPath, "%s\\%s", sDir, fdFile.cFileName);

			//verificam daca este folder sau fisier
			if (fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
			{
				
				for (int i = 1; i <= countStars; i++)
					printf("--->");
				printf("Directory: %s\n\n", sPath);
				countStars++; //incrementam nivelul fiindca ne pregatim de recursivitate
				list(sPath); // apelam recursiv
				countStars--; //decrementam nivelul fiindca am iesit din recursivitate
				
			}
			else {
				for (int i = 1; i <= countStars; i++)
					printf("--->");
				printf("File: %s\n\n", sPath);
			}
		}
	} while (FindNextFile(hFind, &fdFile)); //cautam urmatorul fisier

	FindClose(hFind); 
	
	return "Good"; }



int main()
{
	printf( "UDP Server\n");

	WSADATA WinSockData;
	int iWsaStartup;
	int iWsaCleanup;

	SOCKET UDPSocketServer;
	struct sockaddr_in UDPClient;

	char Buffer[512];
	int iBufferLen = strlen(Buffer) + 1;
	
	char BufferFrom[512];
    int iBufferFromLen = strlen(BufferFrom) + 1;
	char iSendto;
	int iBind;
	int iReceiveFrom;

	int iUDPClientLen = sizeof(UDPClient);
	int iCloseSocket;


	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSockData);
	if (iWsaStartup != 0)
	{
		printf( "Nu am reusit!");
	}
	printf( "WSAStartUp a reusit!");

	//
	UDPClient.sin_family = AF_INET;
	UDPClient.sin_addr.s_addr = inet_addr("127.0.0.1");
	UDPClient.sin_port = htons(8008);

	//
	UDPSocketServer = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (UDPSocketServer == INVALID_SOCKET)
	{
		printf( "Socket nu a reusit sa creeze!");
	}
	printf( "Socket a reusit sa creeze! \n");

	iBind = bind(UDPSocketServer, (SOCKADDR*)&UDPClient, sizeof(UDPClient));
	if (iBind == SOCKET_ERROR)
	{
		printf( "Bind nu a reusit!\n");
	}
	printf( "Bind a reusit!\n");
	
	iReceiveFrom = recvfrom(UDPSocketServer, Buffer, iBufferLen, MSG_PEEK, (SOCKADDR*)&UDPClient, &iUDPClientLen);
	if (iReceiveFrom == SOCKET_ERROR)
	{
				
	}
	
		printf("%s \n", Buffer); //afisam bufferul primit de la client
		char *save[3];
		char comanda[512];
		strcpy(comanda, Buffer);
		// preiau prima bucata 
		char * token = strtok(comanda, " ");
		save[0] = token;
		int ok = 1;
		// separ stringul in mai multe bucati, una e comanda, una path-ul si una daca exista un numeFisier,extensie etc. 
		while (token != NULL) {
			printf(" %s\n", token); //afisam bucatile de string
			token = strtok(NULL, " ");
			save[ok] = token;
			ok++;
		}
		
		
		string command = save[0];
		
	        //executare proces
			if (command.compare("run")==0)
			{
				printf("RUN...\n");
				string com1 = run(save[1]);
				if (com1.compare("Good") == 0) { printf("A pornit!\n"); }
				else { printf("Eroare: %d", WSAGetLastError()); }
			}

			//creare fisier
			if (command.compare("createfile") == 0)
			{
				printf("Create File..\n");
				string com1 = creareFisier(save[1]);
				if (com1.compare("Good") == 0) { printf("S-a creat fisierul!\n"); }
				else { printf("Eroare: %d", WSAGetLastError()); }
			}

			//append fisier
			if (command.compare("appendfile") == 0)
			{
				printf("AppendFile..\n");
				string com1 = appendFisier(save[1],save[2]);
				if (com1.compare("Good") == 0) { printf("S-a appendat fisierul!\n"); }
				else { printf("Eroare: %d", WSAGetLastError()); }
			}

			//sterge un fisier
			if (command.compare("deletefile") == 0)
			{
				printf("Delete File...\n");
				string com1 = deleteFisier(save[1]);
				if (com1.compare("Good") == 0) { printf("S-a sters fisierul!\n"); }
				else { printf("Eroare: %d", WSAGetLastError()); }
				
			}

			//download de fisiere
			if (command.compare("download") == 0)
			{	printf("Download...\n");
				string com1 = download(save[1],save[2]);
				if (com1.compare("Good") == 0) { printf("S-a descarcat fisierul!\n"); }
				else { printf("Eroare: %d\n", WSAGetLastError()); }
			}

			//listare Foldere si fisiere
			if (command.compare("list") == 0)
			{
				printf("List...\n");
				string com1 = list(save[1]);
			}

			//create Key
			if (command.compare("createreg") == 0)
			{
				printf("Create Key...\n");
				string com1 = createKey(save[1],save[2]);
				if (com1.compare("Good") == 0) { printf("S-a creat cheia!\n"); }
				else { printf("Eroare: %d\n", WSAGetLastError()); }
			}

			//delete Key
			if (command.compare("deletereg") == 0)
			{
				printf("Delete Key...\n");
				string com1 = deleteKey(save[1], save[2]);
				if (com1.compare("Good") == 0) { printf("S-a sters cheia!\n"); }
				else {
					printf("Eroare: %d\n", WSAGetLastError());
				}
			}
				
			
		
			/*iSendto = sendto(UDPSocketServer, BufferFrom, iBufferFromLen, MSG_DONTROUTE, (SOCKADDR*)&UDPClient, sizeof(UDPClient));*/
			
			/*if (iSendto == SOCKET_ERROR)
			{
				printf( BufferFrom;
			}
			printf(" Trimis!/n");*/
		
		
	

	iCloseSocket = closesocket(UDPSocketServer);

	if (iCloseSocket == SOCKET_ERROR)
	{
		printf( "Close nu a reusit!\n");
	}
	printf( "Close a reusit!\n");
	
	iWsaCleanup = WSACleanup();
	if (iWsaCleanup == SOCKET_ERROR)
	{
		printf( "Cleanup nu a reusit!\n");
	}
	printf( "Cleanup a reusit!\n");

	system("PAUSE");
	return 0;
}