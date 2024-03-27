/////////////////////////////////////////////////////////////////////////////
// Name:        src/include/internal.h
// Purpose:     Defines the type to be used internally
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "platform.h"

typedef struct WindowFunc {
	void (*pCreated)();
	void (*pMoved)(uint x,uint y);
	void (*pResized)(uint width, uint height);
	void (*pRedrawRequested)();
	void (*pClosed)();
} WindowFunc;

struct ExwlWindow {
	WindowFunc functions;

#ifdef EXWL_PLATFORM_WIN32
	Win32Handle win32;
#elif __linux__
	X11Handle x11;
#endif
};

struct Menubar {
#ifdef EXWL_PLATFORM_WIN32
	Win32MenubarHandle win32;
#elif __linux__
	X11MenubarHandle x11;
#endif
};

struct Menu {
#ifdef EXWL_PLATFORM_WIN32
	Win32MenuHandle win32;
#elif __linux__
	X11MenuHandle x11;
#endif
};