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