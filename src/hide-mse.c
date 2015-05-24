#include <windows.h>
#include <stdio.h>

int
main(void)
{
	HWND w;
	BOOL bret;
	DWORD dret = 0;

	w = FindWindow(NULL, "Microsoft Security Essentials");
	if (w == 0)
	{
		dret = GetLastError();
		printf("FindWindow failed with: %ld\n", dret);
		return 1;
	}

	bret = SetWindowPos(w, 0, 0, 0, 0, 0, SWP_HIDEWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);

	if (bret != 1)
	{
		dret = GetLastError();
		printf("SetWindowPos failed: %ld\n", dret);
		return 1;
	}

	return 0;
}
