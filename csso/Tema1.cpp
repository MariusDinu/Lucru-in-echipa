#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>

using tstring = std::basic_string<TCHAR>;

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
DWORD count = 0;
/* ca sa stiu nivelul arborelui*/

void SearchKey(HKEY hKey,DWORD count,tstring str)
{

	if(count==0)
	CreateDirectory(str.c_str(), NULL); //cream primul folder-radacina
	
	TCHAR    achKey[MAX_KEY_LENGTH];   // numele cheii
	DWORD    cbName;                   // size of name string 
	TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
	DWORD    cchClassName = MAX_PATH;  // size of class string 
	DWORD    cSubKeys = 0;               // number of subkeys 
	DWORD    cbMaxSubKey;              // longest subkey size 
	DWORD    cchMaxClass;              // longest class string 
	DWORD    cValues;              // number of values for key 
	DWORD    cchMaxValue;          // longest value name 
	DWORD    cbMaxValueData;       // longest value data 
	DWORD    cbSecurityDescriptor; 
	FILETIME ftLastWriteTime;      

	DWORD i,j, retCode;
	
	TCHAR  achValue[MAX_VALUE_NAME];
	DWORD cchValue = MAX_VALUE_NAME;

	// Get the class name and the value count. 
	retCode = RegQueryInfoKey(
		hKey,                    // key handle 
		achClass,                // buffer for class name 
		&cchClassName,           // size of class string 
		NULL,                    // reserved 
		&cSubKeys,               // number of subkeys 
		&cbMaxSubKey,            // longest subkey size 
		&cchMaxClass,            // longest class string 
		&cValues,                // number of values for this key 
		&cchMaxValue,            // longest value name 
		&cbMaxValueData,         // longest value data 
		&cbSecurityDescriptor,   // security descriptor 
		&ftLastWriteTime);       // last write time 

	
	/* enumeram subcheile*/
	if (cSubKeys)
	{
		for (i = 0; i < cSubKeys; i++)
		{    
			cbName = MAX_KEY_LENGTH;
			retCode = RegEnumKeyEx(hKey, i,
				achKey,
				&cbName,
				NULL,
				NULL,
				NULL,
				&ftLastWriteTime);

			if (retCode == ERROR_SUCCESS)
			{
				/*adaugam * in functie de nivelul arborelui */
				tstring semn = "*";
				tstring sumSemn;
				for (j = 0; j < count; j++)
				{
					sumSemn = semn + sumSemn;
				}

				/*afisam arborele*/
				_tprintf(TEXT("%s %s\n"), sumSemn.c_str(), achKey);



				tstring initPath = str.c_str();  //aici avem path-ul de la care pornim
				tstring separator = "\\"; //
				tstring keyPath = _T(achKey); //numele cheii actuale
				tstring fullPath = initPath + separator + keyPath; // path-ul final
				CreateDirectory(fullPath.c_str(), NULL); //cream directorul 


				/*apelam recursiv functia pentru a fiecare nivel din arbore*/
				HKEY subKey;
				if (RegOpenKeyEx(hKey,
					achKey,
					0, KEY_READ,
					&subKey) == ERROR_SUCCESS) {
				SearchKey(subKey, count + 1, fullPath.c_str());
			    }

			}
		}
	}

	/*enumeram valorile fiecarei chei*/
	if (cValues)
	{
		//printf("\n Valorile: %d\n", cValues);

		for (i = 0, retCode = ERROR_SUCCESS; i < cValues; i++)
		{
			cchValue = MAX_VALUE_NAME;
			achValue[0] = '\0';
			retCode = RegEnumValue(hKey, i,
				achValue,
				&cchValue,
				NULL,
				NULL,
				NULL,
				NULL);

			if (retCode == ERROR_SUCCESS)
			{
				//_tprintf(TEXT("(%d) %s\n"), i + 1, achValue);
				tstring extension = ".txt"; //extensia fisierului
				tstring namefile = achValue; //numele valorii
				tstring space = "\\"; // separator
				tstring fullFile = str.c_str() +space+ namefile+extension; //path-ul complet al fisierului 

				HANDLE h = CreateFile(fullFile.c_str(),    // name of the file
					GENERIC_WRITE, // open for writing
					0,             // sharing mode, none in this case
					0,             // use default security descriptor
					CREATE_ALWAYS, // overwrite if exists
					FILE_ATTRIBUTE_NORMAL,
					0);
			}
		}
	}

}


int __cdecl _tmain()
{
	HKEY hTestKey;

	if (RegOpenKeyEx(HKEY_CURRENT_CONFIG,
		TEXT(""),
		0,
		KEY_READ,
		&hTestKey) == ERROR_SUCCESS
		)
	{
		tstring str4 = _T("D:\\director6\\");
		SearchKey(hTestKey,0,str4);
	}

	RegCloseKey(hTestKey);
	
}