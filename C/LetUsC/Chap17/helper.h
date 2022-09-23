
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);
HINSTANCE hInst;

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, char * pTitle) {
    HWND h;
    const TCHAR classname[] =  TEXT("My Own Widows");
    WNDCLASSEX wc;

    wc.cbSize = sizeof (wc);
	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC) WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor (NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) (WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = classname;
	wc.hIconSm = LoadIcon (NULL, IDI_APPLICATION);

    hInst = hInstance;

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, TEXT("Could not register window class"),
                NULL, MB_ICONERROR);
        return FALSE;
    }

    h = CreateWindow(classname, pTitle,
                    WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

    if (!h) {
        MessageBox(NULL, TEXT("Could not create window"), NULL, MB_ICONERROR);
        return FALSE;
    }

    ShowWindow(h, nCmdShow);
    UpdateWindow(h);

    return TRUE;
}