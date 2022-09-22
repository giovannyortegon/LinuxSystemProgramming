#include<Windows.h>

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpszCmdLine, int nCmdShow) {
    MessageBox(0, IpszCmdLine, "Title", 0);

    return (0);
}