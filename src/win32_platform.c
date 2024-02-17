#include <Exwl.h>
#include "internal.h"

ExwlWindow* CreateWindowForWin32() {
	ExwlWindow window;

	HINSTANCE hInstance = GetModuleHandleA(NULL);
	HWND hWnd = CreateWindow(TEXT("STATIC"), TEXT("Hello, world"), WS_VISIBLE|WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);

	window.win32.hInstance = hInstance;
	window.win32.hWnd = hWnd;

	ExwlWindow* p_window = malloc(sizeof(window));
	p_window = &window;

	return p_window;
}