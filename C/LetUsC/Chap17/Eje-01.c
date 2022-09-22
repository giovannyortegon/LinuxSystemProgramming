#include<Windows.h>

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpszCmdLine, int nCmdSHow) {
    // MessageBox(0, "Are you sure", "Caption", MB_YESNO);
    MessageBox(0, "Print to the printer", "Caption", MB_YESNOCANCEL);
    MessageBox(0, "Icon is all about style", "Caption", MB_OK|MB_ICONINFORMATION);

    return (0);
}