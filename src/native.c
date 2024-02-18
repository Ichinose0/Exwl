#include <exwl/Exwl.h>
#include <exwl/native.h>
#include "internal.h"
#include <assert.h>

EXWLAPI void* exwlGetHwndOfWindow(ExwlWindow* window) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	return window->win32.hWnd;
#else
	return (void*)0;
#endif
}

EXWLAPI void* exwlGetInstanceOfWindow(ExwlWindow* window) {
	assert(window != NULL);
#ifdef EXWL_PLATFORM_WIN32
	return window->win32.hInstance;
#else
	return (void*)0;
#endif
}