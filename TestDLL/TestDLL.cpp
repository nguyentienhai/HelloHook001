#include <Windows.h>

// vung nho dung chung, chua bien handle cua Hook
#pragma data_seg("SHARED_DATA")
HHOOK hGlobalHook = NULL;
#pragma data_seg()

// ham loc su kien nhan phim
__declspec(dllexport) LRESULT CALLBACK FillKeyboard(int nCode, WPARAM wParam, LPARAM lParam)
{
	// neu su kien la nhan phim va ma phim la Enter
	if ((nCode == HC_ACTION) && (wParam == 13))
	{
		MessageBox(0, L"nguyen tien hai re-write this one ^^", L"Hello Hook", 0);
		return 1;
	}

	// goi FilterFunction ke tiep trong chuoi cac FilterFunction
	return CallNextHookEx(hGlobalHook, nCode, wParam, lParam);
}

// ham an dinh bien hGlobalHook tai vung nho dung chung
__declspec(dllexport) void SetGlobalHookHandle(HHOOK hHook)
{
	hGlobalHook = hHook;
}