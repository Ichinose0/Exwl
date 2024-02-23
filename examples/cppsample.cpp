#include <Exwl/Exwl.h>

int main() {
	Window window("My Window");
	window.setVisible(true);
	while (window.waitWindowMessage()) {
		window.dispatchWindowMessage();
	};
}