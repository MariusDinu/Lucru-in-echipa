#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <sstream>

using namespace std;

HANDLE ghMutex;
LPCTSTR pBuf;

TCHAR mappedFileName[] = TEXT("testMutex.txt"); //fisierul

BOOL SetPrivilege( //functie folosita pentru a seta privilegii(luata de pe docs.microsoft
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


void CalculateB() {//thread 1

	DWORD dwCount = 0, dwWaitResult, A, B;
	TCHAR numere[10];

	while (dwCount < 301)
	{
		dwWaitResult = WaitForSingleObject(//asteptam ca mutexul sa se elibereze
			ghMutex,    // handle to mutex
			INFINITE);  // no time-out interval

		switch (dwWaitResult)
		{
			// S-a eliberat mutexul si a fost ocupat de threadul 1
		case WAIT_OBJECT_0:
			__try {
				A = rand() % 100;//a ul primeste un nr random 0-99
				B = 2 * A;
				sprintf(numere, "%d %d", A, B);//punem a si b intr.un sir de caractere
				memset((PVOID)pBuf, 0, 10);//golim bufferul fisieruli comun
				CopyMemory((PVOID)pBuf, TEXT(numere), strlen(TEXT(numere)));//scriem nr le in fisierul comun
				printf("%d)Am generat: %d %d\n", dwCount, A, B);
				dwCount++;
			}
			__finally {
				// Eliberam mutexul
				if (!ReleaseMutex(ghMutex))
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

void VerifyEquality() {//thread2

	DWORD dwCount = 0, dwWaitResult, A = 0, B = 0, ok = 0;
	TCHAR numere[10];
	// Request ownership of mutex.

	while (dwCount < 301)
	{

		dwWaitResult = WaitForSingleObject(//asteptam eliberarea mutexului
			ghMutex,    // handle to mutex
			INFINITE);  // no time-out interval
		A = 0; B = 0; ok = 0;
		switch (dwWaitResult)
		{
			// S.a eliberat mutexul si il ocupa t2
		case WAIT_OBJECT_0:
			__try {
				strcpy(numere, pBuf); //parsam ceea ce citim din fisierul comun
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


				if (A * 2 == B) {//facem verificarea din cerinta
					printf("%d) Mutex: A= %d e 2 * %d=B\n Corect!\n", dwCount, B, A);
				}
				else {

					printf("Mutex: %d %d numerele fiind %s\n Incorect!\n", A, B, numere);
				}
				dwCount++;

			}
			__finally {

				// Eliberam mutexul
				if (!ReleaseMutex(ghMutex))
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
int main(void)
{

	HANDLE token;

	OpenProcessToken(//facem rost de un token pt procesul curent
		GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES,
		&token
	);

	SetPrivilege(token, SE_CREATE_GLOBAL_NAME, TRUE);//ii dam privilegiul sa creeze fisiere comune

	HANDLE mappedFile = CreateFileMapping(//mapam fisierul comun
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
	pBuf = (LPTSTR)MapViewOfFile(mappedFile, //deschidem fisierul comun
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		10);

	DWORD Thread1ID, Thread2ID;

	// Create a mutex with no initial owner

	ghMutex = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mutex

	if (ghMutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return 1;
	}

	// Create worker threads

	HANDLE t1 = CreateThread(
		NULL,       // default security attributes
		0,          // default stack size
		(LPTHREAD_START_ROUTINE)CalculateB,
		NULL,       // no thread function arguments
		0,          // default creation flags
		&Thread1ID); // receive thread identifier

	printf("Start-Mutex\n");
	HANDLE t2 = CreateThread(
		NULL,       // default security attributes
		0,          // default stack size
		(LPTHREAD_START_ROUTINE)VerifyEquality,
		NULL,       // no thread function arguments
		0,          // default creation flags
		&Thread2ID); // receive thread identifier


	// Wait for all threads to terminate

	WaitForSingleObject(t1, INFINITE);
	WaitForSingleObject(t2, INFINITE);

	// Close thread and mutex handles

	CloseHandle(t1);
	CloseHandle(t2);

	CloseHandle(ghMutex);
	system("pause");
	return 0;
}

