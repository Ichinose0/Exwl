/////////////////////////////////////////////////////////////////////////////
// Name:        Exwl
// Purpose:     Primary header for Exwl
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#pragma once

typedef unsigned char ex_bool;
typedef unsigned int uint;
typedef uint WindowStyle;

typedef struct ExwlWindow ExwlWindow;

#define EX_FALSE 0
#define EX_TRUE 1

#ifdef _WIN32
#define EXWL_PLATFORM_WIN32
#define EXWLAPI __declspec(dllexport)
#elif
#define EXWLAPI  
#endif

#define EXWL_NONE 0x0;
#define EXWL_WINDOW_FRAME 0x01
#define EXWL_WINDOW_CAPTION 0x02
#define EXWL_WINDOW_CLOSABLE 0x04
#define EXWL_WINDOW_MAXIMIZABLE 0x08
#define EXWL_WINDOW_MINIMIZABLE 0x010

#define EXWL_WINDOW_COMPLETE EXWL_WINDOW_FRAME|EXWL_WINDOW_CAPTION|EXWL_WINDOW_CLOSABLE|EXWL_WINDOW_MAXIMIZABLE|EXWL_WINDOW_MINIMIZABLE

typedef struct WindowGeometry {
	uint x;
	uint y;
	uint width;
	uint height;
} WindowGeometry;

typedef struct WindowDescriptor {
	WindowGeometry geometry;
	WindowStyle style;
} WindowDescriptor;

#ifdef __cplusplus
extern "C" {
#endif
	EXWLAPI ExwlWindow* exwlCreateWindow();
	EXWLAPI ExwlWindow* exwlCreateWindowFromDescriptor(WindowDescriptor descriptor);

	EXWLAPI void exwlDefaultWindowGeometry(WindowGeometry* geometry);

	EXWLAPI ex_bool exwlSetWindowSize(ExwlWindow* window, uint width, uint height);
	EXWLAPI ex_bool exwlSetWindowPosition(ExwlWindow* window, uint x, uint y);
	EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, char* title);
	EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible);
	EXWLAPI void exwlSetWindowMaximize(ExwlWindow* window);
	EXWLAPI void exwlSetWindowMinimize(ExwlWindow* window);
	EXWLAPI void exwlSetWindowStyle(ExwlWindow* window, WindowStyle style);
	EXWLAPI ex_bool exwlSetForegroundWindow(ExwlWindow* window);
	EXWLAPI ex_bool exwlGetWindowGeometry(ExwlWindow* window, WindowGeometry* geometry);
	
	EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window);
	EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window);
	EXWLAPI void exwlDestroyWindow(ExwlWindow* window);
#ifdef __cplusplus
}
#endif

// Interface for C++

#ifdef __cplusplus
class Window {
private:
	ExwlWindow* window;
public:
	Window() {
		auto w = exwlCreateWindow();
		window = w;
	}
	Window(char* title) {
		auto w = exwlCreateWindow();
		exwlSetWindowTitle(w, title);
		window = w;
	}
	bool setForeground() {
		return exwlSetForegroundWindow(window);
	}
	void setMaximize() {
		exwlSetWindowMaximize(this->window);
	}
	void setMinimize() {
		exwlSetWindowMinimize(this->window);
	}
	void setVisible(bool visible) {
		exwlSetWindowVisible(this->window, visible);
	}
	void setSize(unsigned int width, unsigned int height) {
		exwlSetWindowSize(this->window, width, height);
	}
	void setStyle(unsigned int style) {
		exwlSetWindowStyle(this->window, style);
	}
	void setTitle(char* title) {
		exwlSetWindowTitle(this->window,title);
	}
	bool getWindowGeometry(WindowGeometry* geometry) {
		return exwlGetWindowGeometry(this->window, geometry);
	}
	bool waitWindowMessage() {
		return exwlWaitWindowMessage(this->window);
	}

	void dispatchWindowMessage() {
		exwlDispatchWindowMessage(this->window);
	}


	~Window() {
		exwlDestroyWindow(this->window);
	}
};
#endif