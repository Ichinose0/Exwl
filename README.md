<h1 align="center">Exwl</h1>
<div align="center">
  <img alt="GitHub License" src="https://img.shields.io/github/license/Ichinose0/Exwl">
  <img alt="CMake on multiple platforms" src="https://github.com/Ichinose0/Exwl/actions/workflows/cmake-multi-platform.yml/badge.svg">
</div>
Exwl is a cross-platform window generation and management library that is easy to extend.

# Example
## Windowing
```c
#include <Exwl/Exwl.h>
#include <stdio.h>

void closed() {
	printf("Window is closed¥n");
	fflush(stdout);
}

int main() {
	ExwlWindow* window = exwlCreateWindow();

	exwlSetWindowTitle(window, "A fantastic window");
	exwlSetWindowVisible(window, ExTrue);

	// Specify the callback function when the window is closed
	exwlClosedFunc(window, closed);

	ex_bool is_running = ExTrue;

	while (is_running) {
		if (exwlWaitEvent(window))
			exwlDispatchWindowMessage(window);
		else
			is_running = ExFalse;
	};

	exwlDestroyWindow(window);
}
```
## C++
```cpp
#include <Exwl/Exwl.h>
#include <iostream>

using namespace std;

void closed() {
	cout << "Window is closed" << endl;
}

int main() {
	Window window("A fantastic window");
	window.setVisible(true);

	// Specify the callback function when the window is closed
	window.setClosedFunc(closed);

	bool is_running = true;

	while (is_running) {
		if (window.waitEvent())
			window.dispatchWindowMessage();
		else
			is_running = false;
	};
}
```

# Build
## Build it yourself
```bash
git clone https://github.com/Ichinose0/Exwl
cd Exwl
cmake -S . -B build
cmake --build build
```
## Download pre-built binaries
It will be available on GitHub Release.
# License
Exwl is licenced under apache-license 2.0
