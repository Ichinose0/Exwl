<h1 align="center">Exwl</h1>
<div align="center">
  <img alt="GitHub License" src="https://img.shields.io/github/license/Ichinose0/Exwl">
</div>
Exwl is a cross-platform window generation and management library that is easy to extend.

# Example
## Windowing
```c
#include <Exwl/Exwl.h>
#include <stdio.h>

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

int main() {
	Window window("My Window");
	window.setVisible(true);
	while (window.waitWindowMessage()) {
		window.dispatchWindowMessage();
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
