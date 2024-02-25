/////////////////////////////////////////////////////////////////////////////
// Name:        src/include/internal.h
// Purpose:     Defines the type to be used internally
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "platform.h"

struct ExwlWindow {
#ifdef EXWL_PLATFORM_WIN32
	Win32Handle win32;
#elif __linux__
	X11Handle x11;
#endif
};