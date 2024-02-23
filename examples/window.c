#include <exwl/Exwl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	ExwlWindow* window = exwlCreateWindow();

	unsigned int style = EXWL_WINDOW_COMPLETE;

	exwlSetWindowTitle(window, "Exwl Window!");
	exwlSetWindowStyle(window,style);
	exwlSetWindowVisible(window, EX_TRUE);

	WindowGeometry geometry;
	exwlGetWindowGeometry(window, &geometry);

	printf("Width: %d\nHeight: %d\nX: %d\nY: %d", geometry.width,geometry.height,geometry.x,geometry.y);

	while (exwlWaitWindowMessage(window)) {
		exwlDispatchWindowMessage(window);
	};

	exwlDestroyWindow(window);
}