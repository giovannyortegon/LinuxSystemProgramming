#include<Windows.h>
#include"helper.h"

void OnLButtonDown(HWND, int, int);
void OnDestroy(HWND);
BOOL InitInstance(HINSTANCE, int, char *);

int x1, y1, x2, y2;

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
        case WM_LBUTTONDOWN:
            OnLButtonDown(hWnd, LOW);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, Lparam);
    }

    return (0);
}

void OnDestroy(HWND hWnd) {
    PostQuitMessage(0);
}

void OnLButtonDown(HWND, int, int) {

}