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
    HGDIOBJ holdpen;

    hdc = BeginPaint(hWnd, &ps);

    hpen = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
    holdpen = SelectObject(hdc, hpen);

    MoveToEx(hdc, 10, 10, NULL);
    LineTo(hdc, 500, 10);

    SelectObject(hdc, holdpen);
    DeleteObject(hpen);

    hpen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
    holdpen = SelectObject(hdc, hpen);

    MoveToEx(hdc, 10, 60, NULL);
    LineTo(hdc, 500, 60);

    SelectObject(hdc, holdpen);
    DeleteObject(hpen);

    hpen = CreatePen(PS_DASHDOT, 1, RGB(255, 0, 0));
    holdpen = SelectObject(hdc, hpen);

    MoveToEx(hdc, 10, 110, NULL);
    LineTo(hdc, 500, 110);

    SelectObject(hdc, holdpen);
    DeleteObject(hpen);
    
    hpen = CreatePen(PS_DASHDOTDOT, 1, RGB(255, 0, 0));
    holdpen = SelectObject(hdc, hpen);

    MoveToEx(hdc, 10, 160, NULL);
    LineTo(hdc, 500, 160);

    SelectObject(hdc, holdpen);
    DeleteObject(hpen);

    hpen = CreatePen(PS_SOLID, 10, RGB(255, 0, 0));
    holdpen = SelectObject(hdc, hpen);

    MoveToEx(hdc, 10, 210, NULL);
    LineTo(hdc, 500, 210);

    SelectObject(hdc, holdpen);
    DeleteObject(hpen);

    EndPaint(hWnd, &ps);
}