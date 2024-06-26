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
typedef uint WindowEvent;

typedef struct ExwlWindow ExwlWindow;
typedef struct Menubar Menubar;
typedef struct Menu Menu;
typedef struct MenuItem MenuItem;
typedef struct CheckMenu CheckMenu;
typedef struct RadioMenu RadioMenu;

#define ExFalse 0
#define ExTrue 1

#if defined(_WIN32)
#define EXWL_PLATFORM_WIN32
#define EXWLAPI __declspec(dllexport)
#elif defined(__linux__)
#define EXWL_PLATFORM_LINUX
#define EXWLAPI
#else
#define EXWLAPI
#endif

#define EXWL_WR_CREATED 0
#define EXWL_WR_REDRAW 12
#define EXWL_WR_MOVED 13
#define EXWL_WR_RESIZED 14
#define EXWL_WR_CLOSED 30
#define EXWL_WR_DESTROY 31

#define EXWL_NONE 0x20
#define EXWL_WS_FRAME 0x40
#define EXWL_WS_CAPTION 0x80
#define EXWL_WS_CLOSABLE 0x100
#define EXWL_WS_MAXIMIZABLE 0x200
#define EXWL_WS_MINIMIZABLE 0x400


#define EXWL_WS_COMPLETE EXWL_WS_FRAME|EXWL_WS_CAPTION|EXWL_WS_CLOSABLE|EXWL_WS_MAXIMIZABLE|EXWL_WS_MINIMIZABLE

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
	
	EXWLAPI void exwlCreatedFunc(ExwlWindow* window, void(*pfunc)());
	EXWLAPI void exwlRedrawRequestedFunc(ExwlWindow* window, void(*pfunc)());
	EXWLAPI void exwlMovedFunc(ExwlWindow* window, void(*pfunc)(uint x,uint y));
	EXWLAPI void exwlResizedFunc(ExwlWindow* window, void(*pfunc)(uint width,uint height));
	EXWLAPI void exwlClosedFunc(ExwlWindow* window, void(*pfunc)());

	EXWLAPI ex_bool exwlWaitEvent(ExwlWindow* window);
	EXWLAPI ex_bool exwlPeekEvent(ExwlWindow* window);
	EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window);
	EXWLAPI void exwlDestroyWindow(ExwlWindow* window);

	EXWLAPI void* exwlGetHwndOfWindow(ExwlWindow* window);
	EXWLAPI void* exwlGetInstanceOfWindow(ExwlWindow* window);

	EXWLAPI ex_bool exwlSetMenubar(Menubar* menubar, ExwlWindow* window);
	EXWLAPI Menubar* exwlCreateMenubar();
	EXWLAPI Menu* exwlInsertMenu(Menubar* menubar,char* text);
	EXWLAPI MenuItem* exwlInsertMenuItem(Menu* menu, char* text);
	EXWLAPI CheckMenu* exwlInsertCheckMenu(Menu* menu, char* text);

	EXWLAPI void exwlSetCheckMenuState(CheckMenu* menu, ex_bool state);
	EXWLAPI ex_bool exwlGetCheckMenuState(CheckMenu* menu);

	EXWLAPI ex_bool exwlDestroyMenubar(Menubar* menubar);
	EXWLAPI ex_bool exwlDeleteMenu(Menubar* menubar, Menu* menu);
#ifdef __cplusplus
}
#endif

// Interface for C++

#ifdef __cplusplus
namespace Exwl {
	void defaultWindowGeometry(WindowGeometry* geometry);
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
			exwlSetWindowTitle(this->window, title);
		}
		bool getWindowGeometry(WindowGeometry* geometry) {
			return exwlGetWindowGeometry(this->window, geometry);
		}

		// Callbacks
		void setCreatedFunc(void(*pfunc)()) {
			exwlCreatedFunc(this->window, pfunc);
		}
		void setRedrawRequestedFunc(void(*pfunc)()) {
			exwlRedrawRequestedFunc(this->window, pfunc);
		}
		void setMovedFunc(void(*pfunc)(uint x, uint y)) {
			exwlMovedFunc(this->window, pfunc);
		}
		void setResizedFunc(void(*pfunc)(uint width, uint height)) {
			exwlResizedFunc(this->window, pfunc);
		}
		void setClosedFunc(void(*pfunc)()) {
			exwlClosedFunc(this->window, pfunc);
		}

		// Event handling
		bool waitEvent() {
			return exwlWaitEvent(this->window);
		}
		bool peekEvent() {
			return exwlPeekEvent(this->window);
		}

		void dispatchWindowMessage() {
			exwlDispatchWindowMessage(this->window);
		}

		void* getHwnd() {
			return exwlGetHwndOfWindow(this->window);
		}

		void* getHinstance() {
			return exwlGetInstanceOfWindow(this->window);
		}


		~Window() {
			exwlDestroyWindow(this->window);
		}
	};
}
#endif