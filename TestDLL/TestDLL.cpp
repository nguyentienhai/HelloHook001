#include <Windows.h>

// vung nho dung chung, chua bien handle cuar Hook
#pragma data_seg("SHARED_DATA")
HHOOK hGlobalHook = NULL;
#pragma data_seg()

// ham loc su kien nhan phim
__declspec(dllexport) LRESULT CALLBACK FillKeyboard(int nHookCode, WPARAM wParam, LPARAM lParam)
{
	// neu su kien la nham phim va ma phim la Enter
	if((nHookCode == HC_ACTION) && (wParam == 13))
	{
		MessageBox(0, L"haint say hello :D", L"HelloHook", 0);
		return 1;
	}

	// goi Filter Function ke tiep trong chuoi cac Filter Function
	return CallNextHookEx(hGlobalHook, nHookCode, wParam, lParam);
}

// ham an dinh bien hGlobal tai vung nho dung chung
__declspec(dllexport) void SetGlobalHookHandle(HHOOK handleHook)
{
	hGlobalHook = handleHook;
}