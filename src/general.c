/////////////////////////////////////////////////////////////////////////////
// Name:        src/general.c
// Purpose:     Implement non-window related functions
// Author:      Ichinose0
// Created:     2024-02-25
/////////////////////////////////////////////////////////////////////////////

#include <Exwl/Exwl.h>
#include <platform.h>

EXWLAPI void exwlDefaultWindowGeometry(WindowGeometry* geometry) {
#ifdef EXWL_PLATFORM_WIN32
	DefaultWindowGeometryForWin32(geometry);
#else

#endif
}