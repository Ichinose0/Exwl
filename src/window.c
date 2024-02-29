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
	return _CreateWindow();
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
	return SetWindowSize(window, width, height);
}

EXWLAPI ex_bool exwlSetWindowPosition(ExwlWindow* window, uint x, uint y) {
	assert(window != NULL);
	return SetWindowPosition(window, x, y);
}

EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, char* title) {
	assert(window != NULL);
	SetWindowTitle(window, title);
}
EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible) {
	assert(window != NULL);
	SetWindowVisible(window, visible);
}

EXWLAPI void exwlSetWindowMaximize(ExwlWindow* window) {
	assert(window != NULL);
	SetWindowMaximize(window);
}
EXWLAPI void exwlSetWindowMinimize(ExwlWindow* window) {
	assert(window != NULL);
	SetWindowMinimize(window);
}
EXWLAPI void exwlSetWindowStyle(ExwlWindow* window, unsigned int style) {
	assert(window != NULL);
	SetWindowStyle(window, style);
}

EXWLAPI ex_bool exwlSetForegroundWindow(ExwlWindow* window) {
	assert(window != NULL);
	return SetForegroundWindow(window);
}

EXWLAPI ex_bool exwlGetWindowGeometry(ExwlWindow* window, WindowGeometry* geometry) {
	assert(window != NULL);
	return GetWindowGeometry(window, geometry);
}

EXWLAPI ex_bool exwlWaitEvent(ExwlWindow* window, EventStruct* e) {
	WaitEventForWin32(window, e);
}
EXWLAPI ex_bool exwlPeekEvent(ExwlWindow* window, EventStruct* e) {
	PeekEventForWin32(window, e);
}
EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window) {
	assert(window != NULL);
	return WaitWindowMessage(window);
}
EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window) {
	assert(window != NULL);
	DispatchWindowMessage(window);
}

EXWLAPI void exwlDestroyWindow(ExwlWindow* window) {
	assert(window != NULL);
	_exwlDestroyWindow(window);
	free(window);
}