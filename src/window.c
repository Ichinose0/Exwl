#include <exwl/Exwl.h>
#include <platform.h>
#include <stdio.h>
#include <stdlib.h>

EXWLAPI ExwlWindow* exwlCreateWindow() {
#ifdef EXWL_PLATFORM_WIN32
	return CreateWindowForWin32();
#else
	return (void*)0;
#endif
}

EXWLAPI ex_bool exwlSetWindowSize(ExwlWindow* window, unsigned int width, unsigned int height) {
#ifdef EXWL_PLATFORM_WIN32
	return SetWindowSizeForWin32(window, width, height);
#else
	return EX_FALSE;
#endif
}

EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, const char* title) {
#ifdef EXWL_PLATFORM_WIN32
	SetWindowTitleForWin32(window,title);
#else

#endif
}
EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible) {
#ifdef EXWL_PLATFORM_WIN32
	SetWindowVisibleForWin32(window,visible);
#else

#endif
}

EXWLAPI void exwlSetWindowMaximize(ExwlWindow* window) {
#ifdef EXWL_PLATFORM_WIN32
	SetWindowMaximizeForWin32(window);
#else

#endif
}
EXWLAPI void exwlSetWindowMinimize(ExwlWindow* window) {
#ifdef EXWL_PLATFORM_WIN32
	SetWindowMinimizeForWin32(window);
#else

#endif
}
EXWLAPI void exwlSetWindowStyle(ExwlWindow* window, unsigned int style) {
#ifdef EXWL_PLATFORM_WIN32
	SetWindowStyleForWin32(window,style);
#else

#endif
}

EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window) {
#ifdef EXWL_PLATFORM_WIN32
	return WaitWindowMessageForWin32(window);
#else
	return EX_FALSE;
#endif
}
EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window) {
#ifdef EXWL_PLATFORM_WIN32
	DispatchWindowMessageForWin32(window);
#else

#endif
}
EXWLAPI void exwlDestroyWindow(ExwlWindow* window) {
	_exwlDestroyWindow(window);
	free(window);
}