/////////////////////////////////////////////////////////////////////////////
// Name:        src/x11_platform.c
// Purpose:     Implementation on X11 platform
// Author:      Ichinose0
// Created:     2024-02-25
/////////////////////////////////////////////////////////////////////////////

#include <stddef.h>

#include <Exwl/Exwl.h>
#include <internal.h>

#include <stdlib.h>
#include <stdio.h>

XAtoms RegisterAtoms(ExwlWindow* window) {
    XAtoms atoms;
    atoms.wmDeleteMessage = XInternAtom(window->x11.display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(window->x11.display, window->x11.window, &atoms.wmDeleteMessage, 1);
    return atoms;
}

ExwlWindow* CreateWindowForX11() {
	ExwlWindow* window = malloc(sizeof(ExwlWindow));
	XEvent event;
	
    window->x11.display = XOpenDisplay(NULL);
    if (window->x11.display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        return NULL;
    }

    int screen_num = DefaultScreen(window->x11.display);
    window->x11.window = XCreateSimpleWindow(window->x11.display, RootWindow(window->x11.display, screen_num), 100, 100, 400, 300, 1,
                                 BlackPixel(window->x11.display, screen_num), WhitePixel(window->x11.display, screen_num));

    window->x11.atoms = RegisterAtoms(window);

	return window;
}

void DefaultWindowGeometryForX11(WindowGeometry* geometry) {

}

ex_bool SetWindowSizeForX11(ExwlWindow* window, uint width, uint height) {

}
ex_bool SetWindowPositionForX11(ExwlWindow* window, uint x, uint y) {

}
void SetWindowTitleForX11(ExwlWindow* window, char* title) {
    XStoreName(window->x11.display, window->x11.window, title);
}
void SetWindowVisibleForX11(ExwlWindow* window, ex_bool visible) {
    if (visible)
        XMapWindow(window->x11.display, window->x11.window);
    else
        XUnmapWindow(window->x11.display, window->x11.window);
}
void SetWindowMaximizeForX11(ExwlWindow* window) {

}
void SetWindowMinimizeForX11(ExwlWindow* window) {

}
void SetWindowStyleForX11(ExwlWindow* window, WindowStyle style) {

}
ex_bool SetForegroundWindowForX11(ExwlWindow* window) {

}

ex_bool GetWindowGeometryForX11(ExwlWindow* window, WindowGeometry* geometry) {
    return ExFalse;
}

ex_bool WaitEventForX11(ExwlWindow* window) {
    XNextEvent(window->x11.display, &window->x11.event);
    return ExTrue;
}
ex_bool PeekEventForX11(ExwlWindow* window) {
    return WaitEventForX11(window);
}
void DispatchWindowMessageForX11(ExwlWindow* window) {
    if (window->x11.event.type == ClientMessage && window->x11.event.xclient.data.l[0] == window->x11.atoms.wmDeleteMessage)
        window->functions.pClosed();
}

void _exwlDestroyWindow(ExwlWindow* window) {
    XDestroyWindow(window->x11.display, window->x11.window);
	XCloseDisplay(window->x11.display);
}