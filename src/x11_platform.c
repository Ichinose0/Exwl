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

	Atom wmDeleteMessage = XInternAtom(window->x11.display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(window->x11.display, window->x11.window, &wmDeleteMessage, 1);

    XMapWindow(window->x11.display, window->x11.window);

    while (1) {
        XNextEvent(window->x11.display, &event);
        if (event.type == ClientMessage && event.xclient.data.l[0] == wmDeleteMessage)
            break;
    }
    
	return window;
}

void _exwlDestroyWindow(ExwlWindow* window) {
	XCloseDisplay(window->x11.display);
}