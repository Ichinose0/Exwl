#include <Exwl.h>
#include <platform.h>

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