#include<Windows.h>
#include"helper.h"

void OnPaint(HWND);
void OnDestroy(HWND);
BOOL InitInstance(HINSTANCE, int, char *);

int _stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdSHow) {
    MSG m;

    InitInstance(hInst, nCmdSHow, "Text");

    while(GetMessage(&m, 0, 0, 0)) {
        DispatchMessage(&m);
    }

    return (0);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM Lparam) {
    switch(message) {
        case WM_DESTROY:
            OnDestroy(hWnd);
            break;
        case WM_PAINT:
            OnPaint(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, Lparam);
    }

    return (0);
}

void OnDestroy(HWND hWnd) {
    PostQuitMessage(0);
}
void OnPaint(HWND hWnd) {
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN hpen;
    HGDIO


    SelectObject(hdc, holdbr);
    DeleteObject(hbr);

    EndPaint(hWnd, &ps);
}