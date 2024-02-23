/////////////////////////////////////////////////////////////////////////////
// Name:        Exwl
// Purpose:     Primary header for Exwl
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#pragma once

typedef unsigned char ex_bool;

typedef struct ExwlWindow ExwlWindow;

#define EXWLAPI __declspec(dllexport)

#define EX_FALSE 0
#define EX_TRUE 1

#ifdef _WIN32
#define EXWL_PLATFORM_WIN32
#endif
#ifdef _LINUX
#define EXWL_PLATFORM_LINUX
#endif

#define EXWL_NONE 0x0;
#define EXWL_WINDOW_FRAME 0x01
#define EXWL_WINDOW_CAPTION 0x02
#define EXWL_WINDOW_CLOSEBOX 0x04
#define EXWL_WINDOW_MAXIMIZEBOX 0x08
#define EXWL_WINDOW_MINIMIZEBOX 0x010

#define EXWL_WINDOW_COMPLETE EXWL_WINDOW_FRAME|EXWL_WINDOW_CAPTION|EXWL_WINDOW_CLOSEBOX|EXWL_WINDOW_MAXIMIZEBOX|EXWL_WINDOW_MINIMIZEBOX

typedef struct WindowGeometry {
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
} WindowGeometry;

#ifdef __cplusplus
extern "C" {
#endif
	EXWLAPI ExwlWindow* exwlCreateWindow();

	EXWLAPI ex_bool exwlSetWindowSize(ExwlWindow* window, unsigned int width, unsigned int height);
	EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, const char* title);
	EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible);
	EXWLAPI void exwlSetWindowMaximize(ExwlWindow* window);
	EXWLAPI void exwlSetWindowMinimize(ExwlWindow* window);
	EXWLAPI void exwlSetWindowStyle(ExwlWindow* window, unsigned int style);
	EXWLAPI ex_bool exwlSetForegroundWindow(ExwlWindow* window);
	EXWLAPI ex_bool exwlGetWindowGeometry(ExwlWindow* window, WindowGeometry* geometry);

	EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window);
	EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window);
	EXWLAPI void exwlDestroyWindow(ExwlWindow* window);
#ifdef __cplusplus
}
#endif