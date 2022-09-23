#include<Windows.h>
#include"helper.h"

void OnDestroy(HWND);
BOOL InitInstance(HINSTANCE, int, char *);

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow) {
    MSG m;

    /* Perform application initialization */
    InitInstance(hInstance, nCmdShow, "Title");

    /* message loop */
    while(GetMessage(&m, 0, 0, 0))
        DispatchMessage(&m);

    return (0);
}
void OnDestroy(HWND hWnd) {
    PostQuitMessage(0);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam) {
    switch (message)
    {
    case WM_DESTROY:
        OnDestroy(hWnd);
        break;
    
    default:
        return DefWindowProc(hWnd, message, wParam, lparam);
    }
    return 0;
}
