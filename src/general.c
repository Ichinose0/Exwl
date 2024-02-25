#include <Exwl/Exwl.h>
#include <platform.h>

EXWLAPI void exwlDefaultWindowGeometry(WindowGeometry* geometry) {
	DefaultWindowGeometryForWin32(geometry);
}