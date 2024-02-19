#include <exwl/Exwl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	ExwlWindow* window = exwlCreateWindow();

	unsigned int style = EXWL_WINDOW_COMPLETE;

	exwlSetWindowTitle(window, "Exwl Window!");
	exwlSetWindowStyle(window,style);
	exwlSetWindowVisible(window, EX_TRUE);

	while (exwlWaitWindowMessage(window)) {
		exwlDispatchWindowMessage(window);
	};

	exwlDestroyWindow(window);
}