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
    HFONT hFont;
    LOGFONT f = {0};
    HGDIOBJ holdfont;
    char * font [] =  {"Arial", "Times New Roman", "Comic Sans MS"};
    int i;
    hdc = BeginPaint(hWnd, &ps);

    for(i = 0; i < 3; i++) {
        strcpy(f.lfFaceName, font[i]);
        f.lfHeight = 40 * (i + 1);
        f.lfItalic = 1;

        hFont = CreateFontIndirect(&f);
        holdfont = SelectObject(hdc, hFont);

        SetTextColor(hdc, RGB(i+1, i+2, 255));
        TextOut(hdc, 10, 70 * i, "Hello Windows", 13);

        SelectObject(hdc, holdfont);
        DeleteObject(hFont);
    }

    EndPaint(hWnd, &ps);
}