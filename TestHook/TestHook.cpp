#include <Windows.h>

// cac bien toan cuc
HHOOK hHook = NULL; // handle cua hook
HMODULE hDLL; // handle cua DLL

// dinh nghia con tro ham SetGlobalHookHandle() trong file DLL
typedef VOID (*LOADPROC)(HHOOK hHook);

BOOL InstallHook();

int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	// cai dat hook, exit neu that bai
	if (InstallHook() == FALSE)
	{
		MessageBox(0, L"Can not install hook!", L"Error", 0);
		return -1;
	}

	MSG msg;
	BOOL bRet;
	// vong lap don va xu ly cac message
	while((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

// ham cai dat hook
BOOL InstallHook()
{
	// load file DLL
	if(LoadLibrary(L"TestDLL.dll") == NULL)
	{
		MessageBox(0, L"Can't load DLL file!!", L"Error", 0);
		return FALSE;
	}

	// lay handle cua file DLL
	HMODULE hDLL = GetModuleHandle(L"TestDLL");
	// exit neu lay handle cua file DLL khong thanh cong
	if (hDLL == NULL)
	{
		MessageBox(0, L"Can't get handle DLL file!!", L"Error", 0);
		return FALSE;
	}

	// cai dat hook, pham vi toan cuc
	hHook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)GetProcAddress(hDLL, "FillKeyboard"), hDLL, 0);
	// exit neu cai dat hook khong thanh cong
	if (hHook == NULL)
	{
		MessageBox(0, L"Can't install hook in global scope!!", L"Error", 0);
		return FALSE;
	}

	// lay dia chi ham SetGlobalHookHandle() trong file DLL
	LOADPROC fPtrFcnt = NULL;
	fPtrFcnt = (LOADPROC)GetProcAddress(hDLL, "GetGlobalHookHandle");
	if (fPtrFcnt == NULL)
	{
		MessageBox(0, L"Can't get address of SetGlobalHookHandle function from DLL file!!", L"Error", 0);
		return FALSE;
	}

	// an dinh handle cua hook vao vung nho dung chung (giua DLL va ung dung nay)
	fPtrFcnt(hHook);

	return TRUE;
}