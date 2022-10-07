#include<Windows.h>
#include"helper.h"

int x1, y_1, x2, y2;

void OnLButtonDown(HWND, int, int);
void OnLButtonUp();
void OnMouseMove(HWND, int , int, int);
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
        case WM_LBUTTONDOWN:
            OnLButtonDown(hWnd, LOWORD(Lparam), HIWORD(Lparam));
            break;
        case WM_LBUTTONUP:
            OnLButtonUp();
            break;
        case WM_MOUSEMOVE:
            OnMouseMove(hWnd, wParam, LOWORD(Lparam), HIWORD(Lparam));
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, Lparam);
    }

    return (0);
}

void OnDestroy(HWND hWnd) {
    PostQuitMessage(0);
}

void OnLButtonDown(HWND hWnd, int x, int y) {
    SetCapture(hWnd);
    x1 = x;
    y_1 = y;
}

void OnLButtonUp() {
    ReleaseCapture();
}
void OnMouseMove(HWND hWnd, int flags, int x, int y) {
    HDC hdc;

    if (flags == MK_LBUTTON) {
        hdc = GetDC(hWnd);
        x2 = x;
        y2 = y;
        MoveToEx(hdc, x1, y_1, NULL);
        LineTo(hdc, x2, y2);
        ReleaseDC(hWnd, hdc);

        x1 = x2;
        y_1 = y2;
    }
}