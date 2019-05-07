class CWnd {
public:
	BOOL CreateEx(DWORD dwExStyle,
		LPCWSTR lpClassName,
		LPCWSTR lpWindowName,
		DWORD dwStyle,
		int X,
		int Y,
		int nWidth,
		int nHeight,
		HWND hWndParent,
		HMENU hMenu,
		HINSTANCE hInstance,
		LPVOID lpParam);
	BOOL ShowWindow(int nCmdShow);
	BOOL UpdateWindow();
public:
	HWND m_hWnd;
};

BOOL CWnd::CreateEx(DWORD dwExStyle, 
					LPCWSTR lpClassName, 
					LPCWSTR lpWindowName, 
					DWORD dwStyle, 
					int X, 
					int Y, 
					int nWidth, 
					int nHeight, 
					HWND hWndParent, 
					HMENU hMenu, 
					HINSTANCE hInstance, 
					LPVOID lpParam) {
	m_hWnd = CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	if (m_hWnd)
		return TRUE;
	else
		return FALSE;
}

BOOL CWnd::ShowWindow(int nCmdShow) {
	return ::ShowWindow(m_hWnd, nCmdShow);
}

BOOL CWnd::UpdateWindow() {
	return ::UpdateWindow(m_hWnd);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	WNDCLASS wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	.....;
	RegisterClass(&wndclass);

	CWnd wnd;
	wnd.CreateEx(...);
	wnd.ShowWindow(SW_SHOWNORMAL);
	wnd.UpdateWindow();

	......;
}
