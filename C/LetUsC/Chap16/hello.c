#include<windows.h>

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR IpszCmdline, int nCmdShow) {
    //MessageBox(0, "Hello !", "Title", 0);
    MessageBox(0, IpszCmdline, "Title", 0);

    return (0);
}