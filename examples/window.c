#include <Exwl/Exwl.h>
#include <stdio.h>

void closed() {
	printf("Window is closed\n");
}

int main() {
	ExwlWindow* window = exwlCreateWindow();

	exwlSetWindowTitle(window, "A fantastic window");
	exwlSetWindowVisible(window, ExTrue);

	Menubar* menubar = exwlCreateMenubar();
	Menu* file = exwlInsertMenu(menubar,"File");
	MenuItem* exit = exwlInsertMenuItem(file, "Exit");
	Menu* edit = exwlInsertMenu(menubar, "Help");
	MenuItem* about = exwlInsertMenuItem(edit, "About");
	exwlSetMenubar(menubar, window);
	

	exwlClosedFunc(window, closed);

	ex_bool is_running = ExTrue;

	while (is_running) {
		if (exwlWaitEvent(window))
			exwlDispatchWindowMessage(window);
		else
			is_running = ExFalse;
	};

	exwlDeleteMenu(menubar, file);
	exwlDeleteMenu(menubar, edit);
	exwlDestroyMenubar(menubar);
	exwlDestroyWindow(window);
}