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

#if defined(EXWL_PLATFORM_WIN32)
EXWLAPI ExwlWindow* exwlCreateWindow() {
	return CreateWindowForWin32();
}

EXWLAPI ex_bool exwlSetWindowSize(ExwlWindow* window, unsigned int width, unsigned int height) {
	assert(window != NULL);
	return SetWindowSizeForWin32(window, width, height);
}

EXWLAPI ex_bool exwlSetWindowPosition(ExwlWindow* window, uint x, uint y) {
	assert(window != NULL);
	return SetWindowPositionForWin32(window, x, y);
}

EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, char* title) {
	assert(window != NULL);
	SetWindowTitleForWin32(window, title);
}
EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible) {
	assert(window != NULL);
	SetWindowVisibleForWin32(window, visible);
}

EXWLAPI void exwlSetWindowMaximize(ExwlWindow* window) {
	assert(window != NULL);
	SetWindowMaximizeForWin32(window);
}
EXWLAPI void exwlSetWindowMinimize(ExwlWindow* window) {
	assert(window != NULL);
	SetWindowMinimizeForWin32(window);
}
EXWLAPI void exwlSetWindowStyle(ExwlWindow* window, unsigned int style) {
	assert(window != NULL);
	SetWindowStyleForWin32(window, style);
}

EXWLAPI ex_bool exwlSetForegroundWindow(ExwlWindow* window) {
	assert(window != NULL);
	return _SetForegroundWindowForWin32(window);
}

EXWLAPI ex_bool exwlGetWindowGeometry(ExwlWindow* window, WindowGeometry* geometry) {
	assert(window != NULL);
	return GetWindowGeometryForWin32(window, geometry);
}

EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window) {
	assert(window != NULL);
	return WaitWindowMessageForWin32(window);
}
EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window) {
	assert(window != NULL);
	DispatchWindowMessageForWin32(window);
}
#elif defined(EXWL_PLATFORM_LINUX)
EXWLAPI ExwlWindow* exwlCreateWindow() {
	return CreateWindowForX11();
}

EXWLAPI ex_bool exwlSetWindowSize(ExwlWindow* window, unsigned int width, unsigned int height) { return ExFalse; }

EXWLAPI ex_bool exwlSetWindowPosition(ExwlWindow* window, uint x, uint y) { return ExFalse; }

EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, char* title) { 
	SetWindowTitleForX11(window,title);
}
EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible) {
	SetWindowVisibleForX11(window,visible);
}

EXWLAPI void exwlSetWindowMaximize(ExwlWindow* window) { }
EXWLAPI void exwlSetWindowMinimize(ExwlWindow* window) { }
EXWLAPI void exwlSetWindowStyle(ExwlWindow* window, unsigned int style) { }

EXWLAPI ex_bool exwlSetForegroundWindow(ExwlWindow* window) { return ExFalse; }

EXWLAPI ex_bool exwlGetWindowGeometry(ExwlWindow* window, WindowGeometry* geometry) { return ExFalse; }

EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window) { return ExFalse; }
EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window) { }
#else
EXWLAPI ExwlWindow* exwlCreateWindow() { return NULL; }

EXWLAPI ex_bool exwlSetWindowSize(ExwlWindow* window, unsigned int width, unsigned int height) { return ExFalse; }

EXWLAPI ex_bool exwlSetWindowPosition(ExwlWindow* window, uint x, uint y) { return ExFalse; }

EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, char* title) { }
EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible) { }

EXWLAPI void exwlSetWindowMaximize(ExwlWindow* window) { }
EXWLAPI void exwlSetWindowMinimize(ExwlWindow* window) { }
EXWLAPI void exwlSetWindowStyle(ExwlWindow* window, unsigned int style) { }

EXWLAPI ex_bool exwlSetForegroundWindow(ExwlWindow* window) { return ExFalse; }

EXWLAPI ex_bool exwlGetWindowGeometry(ExwlWindow* window, WindowGeometry* geometry) { return ExFalse; }

EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window) { return ExFalse; }
EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window) { }
#endif

EXWLAPI ExwlWindow* exwlCreateWindowFromDescriptor(WindowDescriptor descriptor) {
	ExwlWindow* window = exwlCreateWindow();
	if (window == NULL)
		return NULL;
	exwlSetWindowStyle(window, descriptor.style);
	//exwlSetWindowSize(window, descriptor.geometry.width, descriptor.geometry.height);
	exwlSetWindowPosition(window, descriptor.geometry.x, descriptor.geometry.y);
	return window;
}

EXWLAPI void exwlDestroyWindow(ExwlWindow* window) {
	assert(window != NULL);
	_exwlDestroyWindow(window);
	free(window);
}