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
} Win32Handle;

ExwlWindow* CreateWindowForWin32();
#endif