#include <Exwl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	ExwlWindow* window = exwlCreateWindow();

	exwlSetWindowTitle(window, "Exwl Window!");

	while (exwlWaitWindowMessage(window)) {
		exwlDispatchWindowMessage(window);
	};

	exwlDestroyWindow(window);
}