/////////////////////////////////////////////////////////////////////////////
// Name:        src/include/platform.h
// Purpose:     Define handles by platform
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#pragma once

void _exwlDestroyWindow(ExwlWindow* window);

#ifdef _WIN32
#include <Windows.h>

typedef struct t_Win32Handle {
	HINSTANCE hInstance;
	HWND hWnd;
	MSG msg;
} Win32Handle;

ExwlWindow* CreateWindowForWin32();

void DefaultWindowGeometryForWin32(WindowGeometry* geometry);

ex_bool SetWindowSizeForWin32(ExwlWindow* window, uint width, uint height);
ex_bool SetWindowPositionForWin32(ExwlWindow* window, uint x,uint y);
void SetWindowTitleForWin32(ExwlWindow* window, char* title);
void SetWindowVisibleForWin32(ExwlWindow* window, ex_bool visible);
void SetWindowMaximizeForWin32(ExwlWindow* window);
void SetWindowMinimizeForWin32(ExwlWindow* window);
void SetWindowStyleForWin32(ExwlWindow* window, unsigned int style);
/// The function names are prefixed with an underscore to prevent duplication with Windows API function names.
ex_bool _SetForegroundWindowForWin32(ExwlWindow* window);
ex_bool GetWindowGeometryForWin32(ExwlWindow* window, WindowGeometry* geometry);

ex_bool WaitWindowMessageForWin32(ExwlWindow* window);
void DispatchWindowMessageForWin32(ExwlWindow* window);
#endif

#ifdef EXWL_PLATFORM_LINUX
#include <X11/Xlib.h>
#include <X11/Xatom.h>

typedef struct t_X11Handle {
	Display* display;
	Window window;
} X11Handle;
ExwlWindow* CreateWindowForX11();
#endif