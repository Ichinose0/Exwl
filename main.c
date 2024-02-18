#include <exwl/Exwl.h>
#include <exwl/native.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {
	ExwlWindow* window = exwlCreateWindow();

	void* hWnd = exwlGetHwndOfWindow(window);

	exwlSetWindowTitle(window, "Exwl Window!");
	SetWindowText(hWnd, TEXT("Hello World"));

	while (exwlWaitWindowMessage(window)) {
		exwlDispatchWindowMessage(window);
	};

	exwlDestroyWindow(window);
}