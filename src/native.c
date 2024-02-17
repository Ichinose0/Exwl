#include "Exwl.h"

#include "internal.h"
#include "native.h"

ExwlWindow* _exwlCreateWindow() {
#ifdef EXWL_PLATFORM_WIN32
	return CreateWindowForWin32();
#else
	return (void*)0;
#endif
}

EXWLAPI HWND exwlGetHwndFromWindow(ExwlWindow* window) {
	
	return (void*)0;
}