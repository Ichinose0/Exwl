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

EXWLAPI MenuItem* exwlInsertMenuItem(Menu* menu, char* text) {
	return _InsertMenuItem(menu, text);
}

EXWLAPI CheckMenu* exwlInsertCheckMenu(Menu* menu, char* text) {
	return InsertCheckMenu(menu,text);
}



EXWLAPI void exwlSetCheckMenuState(CheckMenu* menu, ex_bool state) {
	SetCheckMenuState(menu, state);
}

EXWLAPI ex_bool exwlGetCheckMenuState(CheckMenu* menu) {
	return GetCheckMenuState(menu);
}



EXWLAPI ex_bool exwlDeleteMenu(Menubar* menubar, Menu* menu) {
	return _DeleteMenu(menubar, menu);
}