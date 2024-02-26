#include <Exwl/Exwl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	WindowGeometry geo;
	WindowDescriptor descriptor;

	exwlDefaultWindowGeometry(&geo);

	descriptor.geometry = geo;
	descriptor.style = EXWL_WS_FRAME|EXWL_WS_CAPTION|EXWL_WS_CLOSABLE;
	ExwlWindow* window = exwlCreateWindowFromDescriptor(descriptor);

	exwlSetWindowTitle(window, "Exwl Window!");
	exwlSetWindowVisible(window, ExTrue);

	WindowGeometry geometry;
	exwlGetWindowGeometry(window, &geometry);

	printf("Width: %d\nHeight: %d\nX: %d\nY: %d", geometry.width,geometry.height,geometry.x,geometry.y);

	while (exwlWaitWindowMessage(window)) {
		exwlDispatchWindowMessage(window);
	};

	exwlDestroyWindow(window);
}