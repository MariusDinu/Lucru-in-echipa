#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <wininet.h>
#define ERROR_OPEN_FILE       10
#define ERROR_MEMORY          11
#define ERROR_SIZE            12
#define ERROR_INTERNET_OPEN   13
#define ERROR_INTERNET_CONN   14
#define ERROR_INTERNET_REQ    15
#define ERROR_INTERNET_SEND   16

#include <windows.h>
#include <wininet.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <tchar.h>
DWORD check(TCHAR sir)
{
	
	DWORD l=0;
	switch (sir)
	{
	case '0':l = 0; return l;
	case '1':l = 1; return l;
	case '2':l = 2; return l;
	case '3':l = 3; return l;
	case '4':l = 4; return l;
	case '5':l = 5; return l;
	case '6':l = 6; return l;
	case '7':l = 7; return l;
	case '8':l = 8; return l;
	case '9':l = 9; return l;
	}
	

	return l;
}
#include <string>
#define SIZE 128
#define MAX_KEY_LENGTH 255
#define STR_EQUAL 0
using tstring = std::basic_string<TCHAR>;

int main()

{
	tstring cuvant = "";
	tstring semn = "";
    DWORD ok = 1;
	tstring numarIp;
	tstring User;
	tstring Pass;
	tstring comanda;
	tstring comandaServer;
	tstring end = "\n";
	tstring command[255];
	DWORD i, j;
	DWORD a = 0;
	HINTERNET Initialize, Connection, File;
	HINTERNET InitializeS, ConnectionS, FileS;
	DWORD dwBytes;
	DWORD numarComenzi=0;
	TCHAR ch;



// initializarea librariei wininet prin apelul functiei InternetOpen
	Initialize = InternetOpen("HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
// conectarea la server si specificarea protocolului
	Connection = InternetConnect(Initialize, "85.122.23.145", INTERNET_DEFAULT_HTTP_PORT,
		NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
//verificarea conectarii
	if (InternetConnect(Initialize, "85.122.23.145", INTERNET_DEFAULT_HTTP_PORT,
		NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0))printf("Internet Connection\n");



//Construirea pachetului http
	File = HttpOpenRequest(Connection,
		"GET",
		"/~george.popoiu/CSSO/info.txt",
		NULL,
		NULL, NULL,
		NULL, 0);
//verificarea constructiei
	if (HttpOpenRequest(Connection,
		"GET",
		"/~george.popoiu/CSSO/info.txt",
		NULL,
		NULL, NULL,
		NULL, 0)) printf("Open Request \n");

	
	
	
//Trimitearea pachetului http+conexiunea cu serverul	
	if (HttpSendRequest(File, NULL, 0, NULL, 0))
	{
		//citim datele din fisier
		while (InternetReadFile(File, &ch, 1, &dwBytes))
		{
			if (dwBytes != 1)break;
			{    semn = TEXT(ch);
			//salvam intr-un tstring
			cuvant = cuvant + semn;

			}
		}
		//afisam ce am salvat
		printf("%s", cuvant.c_str());
	}

	//copiem toate datele intr-un tchar
	TCHAR *cuvant2 = new TCHAR[cuvant.length() + 1];
	copy(cuvant.begin(), cuvant.end(), cuvant2);

	//incepem separarea elementelor
	for (i = 0; i < cuvant.length(); i++)
	{
		if (cuvant2[i] == *end.c_str())
		{
			if(ok!=5)
			ok++;
			else 
			{
				command[a] =comanda.c_str();
				a++;
				comanda.clear();
			}	
		}
		else
		{
			if (ok == 1)
			{
				numarComenzi = numarComenzi * 10 + check(cuvant2[i]); //salvam numarul de comenzi
			}
			if (ok == 2)
			{
				numarIp = numarIp+cuvant2[i]; //salvam ip-ul
			}
			if (ok == 3)
			{
				User = User + cuvant2[i]; //salvam userul
			}
			if (ok == 4)
			{
				Pass = Pass + cuvant2[i]; //salvam parola
			}
			if (ok == 5)
			{
				comanda = comanda + cuvant2[i]; //salvam comenzile
			}		
		}
	}

	//afisam salvarile
	printf("%d \n", numarComenzi);
	printf("%s \n", numarIp.c_str());
	printf("%s \n", User.c_str());
	printf("%s \n", Pass.c_str());
	for (a=0; a < numarComenzi; a++)
	{
		printf("%s \n", command[a].c_str());
	}

	InternetCloseHandle(File);
	InternetCloseHandle(Connection);
	InternetCloseHandle(Initialize);


	//initializarea  librariei wininet prin apelul functiei InternetOpen
	InitializeS = InternetOpen("FTPServer", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	//conectarea
	ConnectionS = InternetConnect(InitializeS, numarIp.c_str(), INTERNET_DEFAULT_FTP_PORT, User.c_str(), Pass.c_str(), INTERNET_SERVICE_FTP, 0, 0);
	//verificarea conectarii
	if (InternetConnect(InitializeS, numarIp.c_str(), INTERNET_DEFAULT_FTP_PORT, User.c_str(), Pass.c_str(), INTERNET_SERVICE_FTP, 0, 0))
	printf("Internet Connection Server\n");
		
	tstring filePath;
	tstring comandaS;
	tstring ext;
	tstring space =" ";
	DWORD count = 0;


	//separare comenzi in comanda server si path
	for (a = 0; a < numarComenzi; a++)
	{
		TCHAR *com = new TCHAR[command[a].length() + 1];
		copy(command[a].begin(), command[a].end(), com);
		for (DWORD z = 0; z < command[a].length()+1; z++)
		{
			if (com[z] == *space.c_str() || z== command[a].length())
			{
				if (count == 3)
				{
					comandaS = comandaServer;
					comandaServer.clear();
				}
				if (count == command[a].length())
				{
					filePath = comandaServer;
				}
				
			}
			else {
				comandaServer = comandaServer + com[z];
				
			}count++;
		}

//separarea in extensie
TCHAR *copyPath = new TCHAR[filePath.length() + 1];
copy(filePath.begin(), filePath.end(), copyPath);
for (DWORD m = filePath.find_last_of('\\'); m < filePath.length(); m++)
{
	ext = ext + copyPath[m];
}

//afisarea datelor ce ajung la consola serverului 
printf("%d %s \n",a, comandaS.c_str());
printf("%d %s \n",a,filePath.c_str());
printf("%d %s \n",a, ext.c_str());


//daca este pentru put urca fisierul pe server
if (comandaS.compare("PUT") == 0)
{
	if (!FtpPutFile(ConnectionS, filePath.c_str(), ext.c_str(), FTP_TRANSFER_TYPE_BINARY, 0))
	{
		printf("Error: %s", GetLastError());
	}
	printf("PUT... \n");
}
else 
//daca este pentru run da jos fisierul (download) si creaza un proces cu path respectiv
if (comandaS.compare("RUN") == 0 )
{
	if (!FtpGetFile(ConnectionS,ext.c_str(),filePath.c_str(), FALSE, FILE_ATTRIBUTE_NORMAL, FTP_TRANSFER_TYPE_ASCII, 0))
	{
		printf("Error: %s", GetLastError());

	}

	//creaza un proces de la path-ul primit
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);

	if (!CreateProcess(filePath.c_str(), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		printf("Cannot create process.\n");
		return 0;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	printf("RUN... \n");

}



ext.clear();


	}
/*
//inchidem conexiunile
	InternetCloseHandle(ConnectionS);
	InternetCloseHandle(InitializeS);
	*/
	return 0;
}

