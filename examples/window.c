#include <Exwl/Exwl.h>
#include <stdio.h>
#include <stdlib.h>

void redraw() {
	printf("Redraw");
}

int main() {

	WindowGeometry geo;
	WindowDescriptor descriptor;

	exwlDefaultWindowGeometry(&geo);

	descriptor.geometry = geo;
	descriptor.style = EXWL_WS_FRAME|EXWL_WS_CAPTION|EXWL_WS_CLOSABLE;
	ExwlWindow* window = exwlCreateWindowFromDescriptor(descriptor);

	exwlSetWindowTitle(window, "Exwl Window!");
	exwlSetWindowVisible(window, ExTrue);

	exwlRedrawRequestedFunc(window, redraw);

	WindowGeometry geometry;
	exwlGetWindowGeometry(window, &geometry);

	printf("Width: %d\nHeight: %d\nX: %d\nY: %d", geometry.width,geometry.height,geometry.x,geometry.y);

	ex_bool is_running = ExTrue;

	EventStruct e;

	while (is_running) {
		if (exwlWaitEvent(window, &e))
			exwlDispatchWindowMessage(window);
		else
			is_running = ExFalse;
	};

	exwlDestroyWindow(window);
}