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

typedef struct t_Win32MenubarHandle {
	HMENU menu;
} Win32MenubarHandle;

typedef struct t_Win32MenuHandle {
	uint id;
} Win32MenuHandle;

ExwlWindow* CreateWindowForWin32();

void DefaultWindowGeometryForWin32(WindowGeometry* geometry);

ex_bool SetWindowSizeForWin32(ExwlWindow* window, uint width, uint height);
ex_bool SetWindowPositionForWin32(ExwlWindow* window, uint x,uint y);
void SetWindowTitleForWin32(ExwlWindow* window, char* title);
void SetWindowVisibleForWin32(ExwlWindow* window, ex_bool visible);
void SetWindowMaximizeForWin32(ExwlWindow* window);
void SetWindowMinimizeForWin32(ExwlWindow* window);
void SetWindowStyleForWin32(ExwlWindow* window, WindowStyle style);
ex_bool SetForegroundWindowForWin32(ExwlWindow* window);
ex_bool GetWindowGeometryForWin32(ExwlWindow* window, WindowGeometry* geometry);

ex_bool WaitEventForWin32(ExwlWindow* window);
ex_bool PeekEventForWin32(ExwlWindow* window);
void DispatchWindowMessageForWin32(ExwlWindow* window);

ex_bool exwlSetMenubarForWin32(Menubar* menubar, ExwlWindow* window);
Menubar* CreateMenubarForWin32();
Menu* InsertMenuForWin32(Menubar* menubar,char* text);
ex_bool DeleteMenuForWin32(Menubar* menubar, Menu* menu);
ex_bool DestroyMenubarForWin32(Menubar* menubar);
#endif

#ifdef EXWL_PLATFORM_LINUX
#include <X11/Xlib.h>
#include <X11/Xatom.h>

typedef struct t_XAtoms {
	Atom wmDeleteMessage;
} XAtoms;

typedef struct t_X11Handle {
	Display* display;
	Window window;
	XEvent event;
	XAtoms atoms;
} X11Handle;

ExwlWindow* CreateWindowForX11();

void DefaultWindowGeometryForX11(WindowGeometry* geometry);

ex_bool SetWindowSizeForX11(ExwlWindow* window, uint width, uint height);
ex_bool SetWindowPositionForX11(ExwlWindow* window, uint x, uint y);
void SetWindowTitleForX11(ExwlWindow* window, char* title);
void SetWindowVisibleForX11(ExwlWindow* window, ex_bool visible);
void SetWindowMaximizeForX11(ExwlWindow* window);
void SetWindowMinimizeForX11(ExwlWindow* window);
void SetWindowStyleForX11(ExwlWindow* window, WindowStyle style);
ex_bool SetForegroundWindowForX11(ExwlWindow* window);
ex_bool GetWindowGeometryForX11(ExwlWindow* window, WindowGeometry* geometry);

ex_bool WaitEventForX11(ExwlWindow* window);
ex_bool PeekEventForX11(ExwlWindow* window);
void DispatchWindowMessageForX11(ExwlWindow* window);
#endif

#ifdef _WIN32
#define _CreateWindow CreateWindowForWin32
#define DefaultWindowGeometry DefaultWindowGeometryForWin32

#define SetWindowSize SetWindowSizeForWin32
#define SetWindowPosition SetWindowPositionForWin32
#define SetWindowTitle SetWindowTitleForWin32
#define SetWindowVisible SetWindowVisibleForWin32
#define SetWindowMaximize SetWindowMaximizeForWin32
#define SetWindowMinimize SetWindowMinimizeForWin32
#define SetWindowStyle SetWindowStyleForWin32
#define SetForegroundWindow SetForegroundWindowForWin32
#define GetWindowGeometry GetWindowGeometryForWin32

#define WaitEvent WaitEventForWin32
#define PeekEvent PeekEventForWin32
#define DispatchWindowMessage DispatchWindowMessageForWin32

#define SetMenubar exwlSetMenubarForWin32
#define CreateMenubar CreateMenubarForWin32
#define _InsertMenu InsertMenuForWin32
#define DestroyMenubar DestroyMenubarForWin32
#define _DeleteMenu DeleteMenuForWin32

#elif defined(__linux__)
#define _CreateWindow CreateWindowForX11
#define DefaultWindowGeometry DefaultWindowGeometryForX11

#define SetWindowSize SetWindowSizeForX11
#define SetWindowPosition SetWindowPositionForX11
#define SetWindowTitle SetWindowTitleForX11
#define SetWindowVisible SetWindowVisibleForX11
#define SetWindowMaximize SetWindowMaximizeForX11
#define SetWindowMinimize SetWindowMinimizeForX11
#define SetWindowStyle SetWindowStyleForX11
#define SetForegroundWindow SetForegroundWindowForX11
#define GetWindowGeometry GetWindowGeometryForX11

#define WaitEvent WaitEventForX11
#define PeekEvent PeekEventForX11
#define DispatchWindowMessage DispatchWindowMessageForX11
#endif