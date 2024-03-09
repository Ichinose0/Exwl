#include <Exwl/Exwl.h>
#include <iostream>

using namespace std;
using namespace Exwl;

void closed() {
	cout << "Window is closed" << endl;
}

int main() {
	Window window("A fantastic window");
	window.setVisible(true);

	window.setClosedFunc(closed);

	bool is_running = true;

	while (is_running) {
		if (window.waitEvent())
			window.dispatchWindowMessage();
		else
			is_running = false;
	};
}