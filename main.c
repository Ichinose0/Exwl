#include <exwl/Exwl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	ExwlWindow* window = exwlCreateWindow();

	exwlSetWindowTitle(window, "Exwl Window!");
	exwlSetWindowVisible(window, EX_TRUE);

	while (exwlWaitWindowMessage(window)) {
		exwlDispatchWindowMessage(window);
	};

	exwlDestroyWindow(window);
}