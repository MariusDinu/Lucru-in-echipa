#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>


HANDLE ghWriteEvent;
HANDLE ghReadEvent;
HANDLE t1, t2;
LPCTSTR pBuf;

TCHAR mappedFileName[] = TEXT("testEvent.txt");//fisierul 

BOOL SetPrivilege(
	HANDLE hToken,          // access token handle
	LPCTSTR lpszPrivilege,  // name of privilege to enable/disable
	BOOL bEnablePrivilege   // to enable or disable privilege
)
{
	TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!LookupPrivilegeValue(
		NULL,            // lookup privilege on local system
		lpszPrivilege,   // privilege to lookup 
		&luid))        // receives LUID of privilege
	{
		printf("LookupPrivilegeValue error: %u\n", GetLastError());
		return FALSE;
	}

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	if (bEnablePrivilege)
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	else
		tp.Privileges[0].Attributes = 0;

	// Enable the privilege or disable all privileges.

	if (!AdjustTokenPrivileges(
		hToken,
		FALSE,
		&tp,
		sizeof(TOKEN_PRIVILEGES),
		(PTOKEN_PRIVILEGES)NULL,
		(PDWORD)NULL))
	{
		printf("AdjustTokenPrivileges error: %u\n", GetLastError());
		return FALSE;
	}

	if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)

	{
		printf("The token does not have the specified privilege. \n");
		return FALSE;
	}

	return TRUE;
}

void CalculateB()//threadul 1
{

	DWORD dwWaitResult;
	DWORD dwCount = 0, A, B;
	TCHAR numere[10];
	printf("Thread %d waiting for write event...\n", GetCurrentThreadId());

	while (dwCount < 301)
	{
		dwWaitResult = WaitForSingleObject(//asteptam semnalarea ca e gata read-ul de pe threadul 2
			ghReadEvent,    // handle to event
			INFINITE);  // no time-out interval

		switch (dwWaitResult)
		{
			// Am primit semnalul
		case WAIT_OBJECT_0:
			__try {
				A = rand() % 100;
				B = 2 * A;
				sprintf(numere, "%d %d", A, B);
				memset((PVOID)pBuf, 0, 10);
				CopyMemory((PVOID)pBuf, TEXT(numere), strlen(TEXT(numere)));
				printf("%d)Am generat: %d %d\n", dwCount, A, B);
				dwCount++;
			}
			__finally {
				// Incheiem semnalul de read ca sa nu continuie t1 degeaba
				if (!ResetEvent(ghReadEvent)) {
					printf("T1:Cannot reset\n");
				}
				if (!SetEvent(ghWriteEvent)) //Dam semnal ca t2 poate sa inceapa sa citeasca(ca scrierea a fost facuta)
				{
					printf("T1:Cannot set\n");
				}

			}

			break;


		case WAIT_ABANDONED:
			return;
		}
	}
}

void VerifyEquality()//thread 2
{

	DWORD dwCount = 0, dwWaitResult, A = 0, B = 0, ok = 0;
	TCHAR numere[10];

	while (dwCount < 301)
	{

		dwWaitResult = WaitForSingleObject(// asteptam semnalul ca e gata write ul de pe t1
			ghWriteEvent,    // handle to event
			INFINITE);  // no time-out interval
		A = 0; B = 0; ok = 0;
		switch (dwWaitResult)
		{
		case WAIT_OBJECT_0:
			__try {
				strcpy(numere, pBuf);
				for (int i = 0; i < strlen(numere); i++) {
					if (ok == 0) {
						if (numere[i] != ' ') {
							A = A * 10 + numere[i] - '0';
						}
						else {
							ok = 1;
						}
					}
					else {
						B = B * 10 + numere[i] - '0';
					}
				}


				if (A * 2 == B) {
					printf("%d) %d e 2 * %d\n", dwCount, B, A);
				}
				else {

					printf(" %d %d numerele fiind %s\n", A, B, numere);
				}
				dwCount++;
			}
			__finally {

				if (!ResetEvent(ghWriteEvent)) {//Incheiem semnalul de write
					printf("Cannot reset\n");
				}
				if (!SetEvent(ghReadEvent))//Incepem semnalul Read pt a debloca t1
				{
					printf("Cannot release\n");
				}

			}
			break;

		case WAIT_ABANDONED:
			return;
		}

	}

}


void CreateEventsAndThreads(void)
{
	int i;
	DWORD Thread1ID, Thread2ID;

	ghWriteEvent = CreateEvent(
		NULL,               // default security attributes
		TRUE,               // manual-reset event
		FALSE,              // initial state is nonsignaled
		TEXT("WriteEvent")  // object name
	);
	ghReadEvent = CreateEvent(
		NULL,               // default security attributes
		TRUE,               // manual-reset event
		FALSE,              // initial state is nonsignaled
		TEXT("ReadEvent")  // object name
	);

	if (ghWriteEvent == NULL)
	{
		printf("CreateEvent failed (%d)\n", GetLastError());
		return;
	}

	if (ghReadEvent == NULL)
	{
		printf("CreateEvent failed (%d)\n", GetLastError());
		return;
	}



	t1 = CreateThread(
		NULL,       // default security attributes
		0,          // default stack size
		(LPTHREAD_START_ROUTINE)CalculateB,
		NULL,       // no thread function arguments
		0,          // default creation flags
		&Thread1ID); // receive thread identifier

	printf("Start-Event\n");
	t2 = CreateThread(
		NULL,       // default security attributes
		0,          // default stack size
		(LPTHREAD_START_ROUTINE)VerifyEquality,
		NULL,       // no thread function arguments
		0,          // default creation flags
		&Thread2ID); // receive thread identifier



}

void WriteToBuffer(VOID)
{
	//Semnalam ca se poate incepe scrierea in t1

	if (!SetEvent(ghReadEvent))
	{
		printf("SetEvent failed (%d)\n", GetLastError());
		return;
	}
}

void CloseEvents()
{
	// Close all event handles (currently, only one global handle).

	CloseHandle(ghWriteEvent);
}

int main(void)
{


	HANDLE token;

	OpenProcessToken(
		GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES,
		&token
	);

	SetPrivilege(token, SE_CREATE_GLOBAL_NAME, TRUE);

	HANDLE mappedFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		10,
		mappedFileName);
	if (mappedFile == NULL)
	{
		printf(("Could not create file mapping object (%d).\n"),
			GetLastError());
		system("pause");
		return 1;
	}
	pBuf = (LPTSTR)MapViewOfFile(mappedFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		10);



	DWORD dwWaitResult;


	CreateEventsAndThreads();

	WriteToBuffer();

	printf("Main thread waiting for threads to exit...\n");


	WaitForSingleObject(t1, INFINITE);//asteptam ca threadurile sa isi termine treaba
	WaitForSingleObject(t2, INFINITE);



	CloseEvents();
	system("pause");
	return 0;
}

