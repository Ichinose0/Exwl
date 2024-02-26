/////////////////////////////////////////////////////////////////////////////
// Name:        src/window.c
// Purpose:     Implementation of window-related functions to be exposed in the header
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#include <Exwl/Exwl.h>
#include <platform.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

EXWLAPI ExwlWindow* exwlCreateWindow() {
#ifdef EXWL_PLATFORM_LINUX
	return CreateWindowForX11();
#endif
#ifdef EXWL_PLATFORM_WIN32
	return CreateWindowForWin32();
#else
	return (void*)0;
#endif
}

EXWLAPI ExwlWindow* exwlCreateWindowFromDescriptor(WindowDescriptor descriptor) {
	ExwlWindow* window = exwlCreateWindow();
	if (window == NULL)
		return NULL;
	exwlSetWindowStyle(window, descriptor.style);
	//exwlSetWindowSize(window, descriptor.geometry.width, descriptor.geometry.height);
	exwlSetWindowPosition(window, descriptor.geometry.x, descriptor.geometry.y);
	return window;
}

EXWLAPI ex_bool exwlSetWindowSize(ExwlWindow* window, unsigned int width, unsigned int height) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	return SetWindowSizeForWin32(window, width, height);
#else
	return EX_FALSE;
#endif
}

EXWLAPI ex_bool exwlSetWindowPosition(ExwlWindow* window, uint x, uint y) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	return SetWindowPositionForWin32(window, x, y);
#else
	return EX_FALSE;
#endif
}

EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, char* title) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	SetWindowTitleForWin32(window,title);
#else

#endif
}
EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	SetWindowVisibleForWin32(window,visible);
#else

#endif
}

EXWLAPI void exwlSetWindowMaximize(ExwlWindow* window) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	SetWindowMaximizeForWin32(window);
#else

#endif
}
EXWLAPI void exwlSetWindowMinimize(ExwlWindow* window) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	SetWindowMinimizeForWin32(window);
#else

#endif
}
EXWLAPI void exwlSetWindowStyle(ExwlWindow* window, unsigned int style) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	SetWindowStyleForWin32(window,style);
#else

#endif
}

EXWLAPI ex_bool exwlSetForegroundWindow(ExwlWindow* window) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	return _SetForegroundWindowForWin32(window);
#else

#endif
}

EXWLAPI ex_bool exwlGetWindowGeometry(ExwlWindow* window, WindowGeometry* geometry) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	return GetWindowGeometryForWin32(window,geometry);
#else
	return EX_FALSE;
#endif
}

EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	return WaitWindowMessageForWin32(window);
#else
	return EX_FALSE;
#endif
}
EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	DispatchWindowMessageForWin32(window);
#else

#endif
}
EXWLAPI void exwlDestroyWindow(ExwlWindow* window) {
	assert(window != NULL);
	_exwlDestroyWindow(window);
	free(window);
}