/////////////////////////////////////////////////////////////////////////////
// Name:        src/include/platform.h
// Purpose:     Define handles by platform
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#pragma once

#ifdef EXWL_PLATFORM_WIN32
#include <Windows.h>

typedef struct t_Win32Handle {
	HINSTANCE hInstance;
	HWND hWnd;
	MSG msg;
} Win32Handle;

ExwlWindow* CreateWindowForWin32();
ex_bool SetWindowSizeForWin32(ExwlWindow* window, unsigned int width, unsigned int height);
void SetWindowTitleForWin32(ExwlWindow* window, const char* title);
void SetWindowVisibleForWin32(ExwlWindow* window, ex_bool visible);
void SetWindowMaximizeForWin32(ExwlWindow* window);
void SetWindowMinimizeForWin32(ExwlWindow* window);

ex_bool WaitWindowMessageForWin32(ExwlWindow* window);
void DispatchWindowMessageForWin32(ExwlWindow* window);
void _exwlDestroyWindow(ExwlWindow* window);
#endif