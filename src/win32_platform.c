/////////////////////////////////////////////////////////////////////////////
// Name:        src/win32_platform.c
// Purpose:     Implementation on Win32 platform
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#include <Exwl/Exwl.h>
#include <stdlib.h>
#include "internal.h"
#include <stdio.h>
#include <time.h>

uint genId() {
	static INITIALIZED = ExFalse;
	if (!INITIALIZED) {
		srand((unsigned)time(NULL));
		INITIALIZED = ExTrue;
	}
	return rand() % MAXSHORT;
}

DWORD ExtractWindowStyle(unsigned int style) {
	DWORD s = WS_VISIBLE;
	if (style & EXWL_WS_FRAME) {
		s |= WS_BORDER | WS_THICKFRAME;
	}
	if (style & EXWL_WS_CAPTION) {
		s |= WS_CAPTION;
	}
	if (style & EXWL_WS_CLOSABLE)
		s |= WS_SYSMENU;
	if (style & EXWL_WS_MAXIMIZABLE)
		s |= WS_MAXIMIZEBOX;
	if (style & EXWL_WS_MINIMIZABLE) {
		s |= WS_MINIMIZEBOX;
	}

	return s;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_CREATE:
	{
		LONG_PTR p = GetWindowLongPtr(hwnd, GWLP_USERDATA);
		if (p != NULL) {
			WindowFunc* functions = (WindowFunc*)p;
			if (functions->pCreated != NULL)
				functions->pCreated();
		}
		break;
	}
	case WM_MOVE:
	{
		LONG_PTR p = GetWindowLongPtr(hwnd, GWLP_USERDATA);
		if (p != NULL) {
			WindowFunc* functions = (WindowFunc*)p;
			if (functions->pMoved != NULL)
				functions->pMoved((uint)LOWORD(lp), (uint)HIWORD(lp));
		}
		break;
	}
	case WM_SIZE:
	{
		LONG_PTR p = GetWindowLongPtr(hwnd, GWLP_USERDATA);
		if (p != NULL) {
			WindowFunc* functions = (WindowFunc*)p;
			if (functions->pResized != NULL)
				functions->pResized((uint)LOWORD(lp), (uint)HIWORD(lp));
		}
		break;
	}
	case WM_PAINT:
	{
		LONG_PTR p = GetWindowLongPtr(hwnd, GWLP_USERDATA);
		if (p != NULL) {
			WindowFunc* functions = (WindowFunc*)p;
			if (functions->pRedrawRequested != NULL)
				functions->pRedrawRequested();
		}
		break;
	}
	case WM_DESTROY:
	{
		LONG_PTR p = GetWindowLongPtr(hwnd, GWLP_USERDATA);
		if (p != NULL) {
			WindowFunc* functions = (WindowFunc*)p;
			if (functions->pClosed != NULL)
				functions->pClosed();
		}
		PostQuitMessage(0);
		break;
	}
	};
	return DefWindowProc(hwnd, msg, wp, lp);
}

ExwlWindow* CreateWindowForWin32() {
	ExwlWindow* window = malloc(sizeof(ExwlWindow));

	HINSTANCE hInstance = GetModuleHandleA(NULL);
	WNDCLASS winc;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("DEF");

	if (!RegisterClass(&winc)) return NULL;

	HWND hWnd = CreateWindow(TEXT("DEF"), TEXT("Hello, world"), WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);
	SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)&window->functions);
	window->win32.hInstance = hInstance;
	window->win32.hWnd = hWnd;

	return window;
}

void DefaultWindowGeometryForWin32(WindowGeometry* geometry) {
	int width = GetSystemMetrics(SM_CXSCREEN)*1.25;
	int height = GetSystemMetrics(SM_CYSCREEN)*1.25;

	geometry->width = width / 2;
	geometry->height = height / 2;
	geometry->x = width/geometry->width;
	geometry->y = width/geometry->height;
}

ex_bool SetWindowSizeForWin32(ExwlWindow* window, unsigned int width, unsigned int height) {
	return MoveWindow(window->win32.hWnd,0,0,(int)width,(int)height,0);
}

ex_bool SetWindowPositionForWin32(ExwlWindow* window, uint x, uint y) {
	return SetWindowPos(window->win32.hWnd, NULL, x,y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void SetWindowTitleForWin32(ExwlWindow* window, char* title) {
	SetWindowText(window->win32.hWnd, title);
}

void SetWindowVisibleForWin32(ExwlWindow* window, ex_bool visible) {
	if (visible)
		ShowWindow(window->win32.hWnd, SW_SHOW);
	else
		ShowWindow(window->win32.hWnd, SW_HIDE);
}

void SetWindowMaximizeForWin32(ExwlWindow* window) {
	ShowWindow(window->win32.hWnd, SW_MAXIMIZE);
}
void SetWindowMinimizeForWin32(ExwlWindow* window) {
	ShowWindow(window->win32.hWnd, SW_MINIMIZE);
}
void SetWindowStyleForWin32(ExwlWindow* window, unsigned int style) {
	SetWindowLong(window->win32.hWnd,GWL_STYLE, ExtractWindowStyle(style));
	SetWindowPos(window->win32.hWnd, NULL, 0, 0, 0, 0, (SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED));
}

ex_bool SetForegroundWindowForWin32(ExwlWindow* window) {
	return SetForegroundWindow(window->win32.hWnd);
}

ex_bool GetWindowGeometryForWin32(ExwlWindow* window, WindowGeometry* geometry) {
	WINDOWINFO info;
	info.cbSize = sizeof(WINDOWINFO);
	if (!GetWindowInfo(window->win32.hWnd, &info))
		return ExFalse;

	// Width
	geometry->width = info.rcWindow.right - info.rcWindow.left;
	// Height
	geometry->height = info.rcWindow.bottom - info.rcWindow.top;
	// X
	geometry->x = info.rcWindow.left;
	// Y
	geometry->y = info.rcWindow.top;
	return ExTrue;
}

ex_bool WaitEventForWin32(ExwlWindow* window) {
	if (window != NULL) {
		BOOL result = GetMessage(&(window->win32.msg), NULL, 0, 0);
		return result;
	}
	else
		return ExFalse;
}
ex_bool PeekEventForWin32(ExwlWindow* window) {
	if (window != NULL)
		return PeekMessage(&window->win32.msg, NULL, 0, 0, PM_NOREMOVE);
	else
		return ExFalse;
}
void DispatchWindowMessageForWin32(ExwlWindow* window) {
	DispatchMessage(&(window->win32.msg));
}

void _exwlDestroyWindow(ExwlWindow* window) {
	DestroyWindow(window->win32.hWnd);
}

ex_bool exwlSetMenubarForWin32(Menubar* menubar, ExwlWindow* window) {
	SetMenu(window->win32.hWnd, menubar->win32.menu);
	return ExTrue;
}

Menubar* CreateMenubarForWin32() {
	Menubar* menubar = malloc(sizeof(Menubar));
	menubar->win32.menu = CreateMenu();
	return menubar;
}

Menu* InsertMenuForWin32(Menubar* menubar,char* text) {
	Menu* menu = malloc(sizeof(Menu));
	menu->win32.id = genId();
	menu->win32.submenu = CreatePopupMenu();

	MENUITEMINFO mii;
	//memset(&mii, 0, sizeof(MENUITEMINFO));
	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_ID | MIIM_STRING | MIIM_SUBMENU;
	mii.wID = menu->win32.id;
	mii.hSubMenu = menu->win32.submenu; //◆サブメニューの追加
	mii.dwTypeData = TEXT(text);
	InsertMenuItem(menubar->win32.menu, menu->win32.id, FALSE, &mii);
	return menu;
}

MenuItem* InsertMenuItemForWin32(Menu* menu, char* text) {
	MenuItem* item = malloc(sizeof(MenuItem));
	item->win32.id = genId();
	item->win32.parent = menu->win32.submenu;
	MENUITEMINFO mii;
	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_ID | MIIM_STRING;
	mii.wID = item->win32.id;
	mii.dwTypeData = TEXT(text);
	InsertMenuItem(menu->win32.submenu, item->win32.id, FALSE, &mii);
	return item;
}

CheckMenu* InsertCheckMenuForWin32(Menu* menu, char* text) {
	CheckMenu* item = malloc(sizeof(CheckMenu));
	item->win32.id = genId();
	item->win32.parent = menu->win32.submenu;
	MENUITEMINFO mii;
	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_ID | MIIM_STRING | MIIM_STATE;
	mii.fState = MFS_UNCHECKED;
	mii.wID = item->win32.id;
	mii.dwTypeData = TEXT(text);
	InsertMenuItem(menu->win32.submenu, item->win32.id, FALSE, &mii);
	return item;
}



void SetCheckMenuStateForWin32(CheckMenu* menu, ex_bool state) {
	MENUITEMINFO mii;
	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_STATE;

	if (state)
		mii.fState = MFS_CHECKED;
	else
		mii.fState = MFS_UNCHECKED;

	SetMenuItemInfo(menu->win32.parent, menu->win32.id, FALSE, &mii);
}

ex_bool GetCheckMenuStateForWin32(CheckMenu* menu) {
	uint state = GetMenuState(menu->win32.parent, menu->win32.id, FALSE);
	
	if (state == MFS_CHECKED)
		return ExTrue;
	else
		return ExFalse;
}

ex_bool DestroyMenubarForWin32(Menubar* menubar) {
	ex_bool result = DeleteMenu(menubar->win32.menu, 0, 0);
	free(menubar);
	return result;
}

ex_bool DeleteMenuForWin32(Menubar* menubar, Menu* menu) {
	ex_bool result;
	result = DeleteMenu(menubar->win32.menu, menu->win32.id, 0);
	free(menu);
	return result;
}