#include<Windows.h>

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
    HWND h[10];
    int x;

    for (int x = 0; x <= 9; x++) {
        h[x] = CreateWindow("BUTTON", "Press Me", WS_EX_OVERLAPPEDWINDOW, x * 20, x * 20, 250, 200, 0, 0, hInstance, 0);
        ShowWindow(h[x], nCmdShow);
        MessageBox(0, "Hi!", "Waiting", 0);
    }

    MessageBox(0, "Hi!", "Waiting", 0);

    return (0);
}