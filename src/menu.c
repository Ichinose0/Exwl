/////////////////////////////////////////////////////////////////////////////
// Name:        src/menu.c
// Purpose:     Implementation of Menu
// Author:      Ichinose0
// Created:     2024-03-26
/////////////////////////////////////////////////////////////////////////////

#include <Exwl/Exwl.h>
#include <internal.h>
#include <platform.h>

EXWLAPI ex_bool exwlSetMenubar(Menubar* menubar, ExwlWindow* window) {
	return SetMenubar(menubar, window);
}

EXWLAPI Menubar* exwlCreateMenubar() {
	return CreateMenubar();
}

EXWLAPI ex_bool exwlDestroyMenubar(Menubar* menubar) {
	return DestroyMenubar(menubar);
}

EXWLAPI Menu* exwlInsertMenu(Menubar* menubar,char* text) {
	return _InsertMenu(menubar,text);
}



EXWLAPI ex_bool exwlDeleteMenu(Menubar* menubar, Menu* menu) {
	return _DeleteMenu(menubar, menu);
}