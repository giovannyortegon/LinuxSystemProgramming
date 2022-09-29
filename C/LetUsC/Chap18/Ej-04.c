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
    HBRUSH hbr;
    HGDIOBJ holdbr;
    HBITMAP hbmp;

    hdc = BeginPaint(hWnd, &ps);

    hbr = CreateSolidBrush(RGB(255, 0, 0));
    holdbr =  SelectObject(hdc, hbr);

    Rectangle(hdc, 5, 5, 105, 100);

    SelectObject(hdc, holdbr);
    DeleteObject(hbr);

    hbr = CreateHatchBrush(HS_CROSS, RGB(255, 0, 0));
    holdbr = SelectObject(hdc, hbr);

    Rectangle(hdc, 125, 5, 225, 100);

    SelectObject(hdc, holdbr);
    DeleteObject(hbr);

    // hbmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));

    // hbr = CreatePatternBrush(hbmp);
    // holdbr = SelectObject(hdc, hbr);

    // Rectangle(hdc, 245, 5, 345, 100);

    // SelectObject(hdc, holdbr);
    // DeleteObject(hbr);
    // DeleteObject(hbmp);

    EndPaint(hWnd, &ps);

    DeleteObject(hbr);
}