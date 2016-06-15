//===============================================================================================//
// This is a stub for the actuall functionality of the DLL.
//===============================================================================================//
#include "ReflectiveLoader.h"

// Note: REFLECTIVEDLLINJECTION_VIA_LOADREMOTELIBRARYR and REFLECTIVEDLLINJECTION_CUSTOM_DLLMAIN are
// defined in the project properties (Properties->C++->Preprocessor) so as we can specify our own 
// DllMain and use the LoadRemoteLibraryR() API to inject this DLL.

// You can use this value as a pseudo hinstDLL value (defined and set via ReflectiveLoader.c)
extern HINSTANCE hAppInstance;
//===============================================================================================//
BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved )
{
    BOOL bReturnValue = TRUE;
	TCHAR szFileName[MAX_PATH];
	int i = 0;
	BOOL isCalc = FALSE;
	int ki = 0;
	int keys[] = { VK_NUMPAD3, VK_NUMPAD1, VK_NUMPAD1, VK_NUMPAD3, VK_NUMPAD7, VK_ADD, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_NUMPAD4, VK_NUMPAD9, VK_SUBTRACT, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD8, VK_NUMPAD9, VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD1, VK_NUMPAD3, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9, VK_SUBTRACT, VK_NUMPAD8, VK_NUMPAD0, VK_NUMPAD0, VK_NUMPAD8, VK_NUMPAD5, VK_SUBTRACT, VK_ADD, VK_SUBTRACT, VK_MULTIPLY, VK_ADD, VK_NUMPAD4, VK_NUMPAD3, VK_NUMPAD7, VK_NUMPAD7, VK_NUMPAD0, VK_SUBTRACT, VK_NUMPAD4, VK_NUMPAD2, VK_RETURN};
	int end = 27;
	switch( dwReason ) 
    { 
		case DLL_QUERY_HMODULE:
			if( lpReserved != NULL )
				*(HMODULE *)lpReserved = hAppInstance;
			break;
		case DLL_PROCESS_ATTACH:
			hAppInstance = hinstDLL;
			GetModuleFileName(NULL, szFileName, MAX_PATH);
			while (szFileName[i]) {
				if (szFileName[i] == 'c' && szFileName[i + 1] == 'a' && szFileName[i + 2] == 'l' && szFileName[i + 3] == 'c' && szFileName[i + 4] == '.' && szFileName[i + 5] == 'e' && szFileName[i + 6] == 'x' && szFileName[i + 7] == 'e') {
					isCalc = TRUE;
					break;
				}
				i++;
			}

			if (!isCalc) {
				ExitProcess(0);
			}

			while (TRUE) {
				Sleep(10);
				if (GetAsyncKeyState(VK_NUMPAD0) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD0) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD1) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD1) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD2) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD2) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD3) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD3) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD4) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD4) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD5) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD5) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD6) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD6) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD7) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD7) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD8) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD8) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_NUMPAD9) & 0x80000000) {
					if (keys[ki] == VK_NUMPAD9) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_MULTIPLY) & 0x80000000) {
					if (keys[ki] == VK_MULTIPLY) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_ADD) & 0x80000000) {
					if (keys[ki] == VK_ADD) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_SUBTRACT) & 0x80000000) {
					if (keys[ki] == VK_SUBTRACT) {
						ki++;
					}
				}
				if (GetAsyncKeyState(VK_RETURN) & 0x80000000) {
					if (keys[ki] == VK_RETURN) {
						ki++;
					}
				}

				if (ki == end) {
					MessageBoxA(NULL, "Awesome! Now md5sum the integer result as a string and submit that as a flag.", "X-CTF", MB_OK);
					break;
				}
			}
			break;
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
            break;
    }
	return bReturnValue;
}