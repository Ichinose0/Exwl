#include <Exwl.h>
#include "internal.h"
#include <stdio.h>

ExwlWindow* CreateWindowForWin32() {
	ExwlWindow window;

	HINSTANCE hInstance = GetModuleHandleA(NULL);
	WNDCLASS winc;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = DefWindowProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("DEF");

	if (!RegisterClass(&winc)) return NULL;

	HWND hWnd = CreateWindow(TEXT("DEF"), TEXT("Hello, world"), WS_VISIBLE|WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);

	window.win32.hInstance = hInstance;
	window.win32.hWnd = hWnd;

	ExwlWindow* p_window = malloc(sizeof(window));
	p_window = &window;

	return p_window;
}

ex_bool SetWindowSizeForWin32(ExwlWindow* window, unsigned int width, unsigned int height) {
	return MoveWindow(window->win32.hWnd,0,0,(int)width,(int)height,0);
}

void SetWindowTitleForWin32(ExwlWindow* window, const char* title) {
	SetWindowText(window->win32.hWnd, title);
}

void SetWindowVisibleForWin32(ExwlWindow* window, ex_bool visible) {
	if (visible)
		ShowWindow(window->win32.hWnd, SW_SHOW);
	else
		ShowWindow(window->win32.hWnd, SW_HIDE);
}