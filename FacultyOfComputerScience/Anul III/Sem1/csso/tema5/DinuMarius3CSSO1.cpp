
#pragma comment(lib, "advapi32.lib")

#include <windows.h>
#include <stdio.h>
#include <aclapi.h>
#include <tchar.h>

int main()
{
	BYTE bSID[SECURITY_MAX_SID_SIZE];
	BOOL bRVal;
	DWORD dwSidSize = SECURITY_MAX_SID_SIZE;

	LPTSTR szSID = NULL;

	TCHAR szUserName[256], szDomainName[256];
	DWORD dwUserSize = _tcslen(szUserName);
	DWORD dwDomainSize = _tcslen(szDomainName);

	SID_NAME_USE snu = SidTypeInvalid;
	//preluam numele utilizatorului curent care dupa parerea mea e si ownerul a ceea ce face
	TCHAR tchBuffer[256];
	//_tcslen l-am folosit in loc de strlen
	DWORD dwBufferSize = _tcslen(tchBuffer);

	if (GetUserName(tchBuffer, &dwBufferSize)) {
		printf("Username primit.\n");
	}
	else {
		printf("Nu pot prelua numele.\n");
		exit(EXIT_FAILURE);
	}

	_tprintf(_T("Username =: %s\n"), tchBuffer);



	bRVal = LookupAccountName(
		NULL, //use this system
		tchBuffer, //the user to look up
		bSID, //the returned SID
		&dwSidSize, //the size of the SID returned
		szDomainName, //the returned domain name
		&dwDomainSize, //the size of the domain name
		&snu //the type of sid
	);
	_tprintf(_T("SID %d pentru %s in %s .\n"), bSID, tchBuffer, szDomainName);
		



	DWORD dwRes, dwDisposition;
	PSID pEveryoneSID = NULL, pOwnerSID = bSID;
	PACL pACL = NULL;
	PSECURITY_DESCRIPTOR pSD = NULL;
	EXPLICIT_ACCESS ea[2];
	SID_IDENTIFIER_AUTHORITY SIDAuthWorld =
		SECURITY_WORLD_SID_AUTHORITY;
	SID_IDENTIFIER_AUTHORITY SIDAuthNT = SECURITY_CREATOR_SID_AUTHORITY;
	SECURITY_ATTRIBUTES sa;
	LONG lRes;
	HKEY hkSub = NULL;

	//sid pentru toti
	{
	// facem sid-ul pentru toti userii
	if (!AllocateAndInitializeSid(&SIDAuthWorld, 1,
		SECURITY_WORLD_RID,
		0, 0, 0, 0, 0, 0, 0,
		&pEveryoneSID))
	{
		_tprintf(_T("AllocateAndInitializeSid Error %u\n"), GetLastError());
	}
	// le dam drepturi doar de citire asupra unei key pe care o vom crea
	ZeroMemory(&ea, 2 * sizeof(EXPLICIT_ACCESS));
	ea[0].grfAccessPermissions = KEY_READ;
	ea[0].grfAccessMode = SET_ACCESS;
	ea[0].grfInheritance = NO_INHERITANCE;
	ea[0].Trustee.TrusteeForm = TRUSTEE_IS_SID;
	ea[0].Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
	ea[0].Trustee.ptstrName = (LPTSTR)pEveryoneSID;
}


	{
		// facem sid-ul pentru owner
		// folosim sid-ul pentru grupul local de administrare
		if (!AllocateAndInitializeSid(&SIDAuthNT, 2,
			SECURITY_BUILTIN_DOMAIN_RID,
			DOMAIN_ALIAS_RID_ADMINS,
			0, 0, 0, 0, 0, 0,
			&pOwnerSID))
		{
			_tprintf(_T("AllocateAndInitializeSid Error %u\n"), GetLastError());
			
		}
		
		// Explicit_acces for aCE
		// cu acest Ace voi avea drepturi pentru owner depline
		ea[1].grfAccessPermissions = KEY_ALL_ACCESS;
		ea[1].grfAccessMode = SET_ACCESS;
		ea[1].grfInheritance = NO_INHERITANCE;
		ea[1].Trustee.TrusteeForm = TRUSTEE_IS_SID;
		ea[1].Trustee.TrusteeType = TRUSTEE_IS_GROUP;
		ea[1].Trustee.ptstrName = (LPTSTR)pOwnerSID;
	}

	
	// ACL
	dwRes = SetEntriesInAcl(2, ea, NULL, &pACL);
	if (ERROR_SUCCESS != dwRes)
	{
		_tprintf(_T("SetEntriesInAcl Error %u\n"), GetLastError());
		
	}
	
	//security descriptor.  
	pSD = (PSECURITY_DESCRIPTOR)LocalAlloc(LPTR,
		SECURITY_DESCRIPTOR_MIN_LENGTH);
	if (NULL == pSD)
	{
		_tprintf(_T("LocalAlloc Error %u\n"), GetLastError());
	
	}

	if (!InitializeSecurityDescriptor(pSD,
		SECURITY_DESCRIPTOR_REVISION))
	{
		_tprintf(_T("InitializeSecurityDescriptor Error %u\n"),
			GetLastError());
	
	}

	// adaugam acl la security descriptor. 
	if (!SetSecurityDescriptorDacl(pSD,
		TRUE,     // bDaclPresent flag   
		pACL,
		FALSE))   // not a default DACL 
	{
		_tprintf(_T("SetSecurityDescriptorDacl Error %u\n"),
			GetLastError());
		
	}

	// facem un security atributes
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = pSD;
	sa.bInheritHandle = FALSE;

	// folosim acest atributes pentru a seta cine are si cine nu drepturi asupra acelei chei
	lRes = RegCreateKeyEx(HKEY_CURRENT_USER, _T("\SOFTWARE\\mykey3"), 0, NULL, 0,
		KEY_READ | KEY_WRITE, &sa, &hkSub, &dwDisposition);
	_tprintf(_T("RegCreateKeyEx result %u\n"), lRes);

	//HKEY_CURRENT_CONFIG\Software
	//HKEY_CURRENT_USER\SOFTWARE
	//HKEY_LOCAL_MACHINE\SOFTWARE
	
	return 0;
}