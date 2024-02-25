#include <Exwl/Exwl.h>
#include <platform.h>

EXWLAPI void exwlDefaultWindowGeometry(WindowGeometry* geometry) {
#ifdef EXWL_PLATFORM_WIN32
	DefaultWindowGeometryForWin32(geometry);
#else

#endif
}