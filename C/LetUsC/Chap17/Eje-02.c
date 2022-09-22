#include<Windows.h>

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
    HWND h;

    h = CreateWindow("BUTTON", "Press Me", WS_OVERLAPPEDWINDOW, 250, 250, 250, 200, 0, 0, hInstance, 0);
    ShowWindow(h, nCmdShow);
    MessageBox(0, "Hi!", "Waiting", MB_OK);

    return (0);
}