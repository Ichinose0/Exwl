/////////////////////////////////////////////////////////////////////////////
// Name:        Exwl
// Purpose:     Primary header for Exwl
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#pragma once

typedef unsigned char ex_bool;

typedef struct ExwlWindow ExwlWindow;

#define EXWLAPI __declspec(dllexport)
#define EX_FALSE 0
#define EX_TRUE 1

#ifdef _WIN32
#define EXWL_PLATFORM_WIN32
#endif
#ifdef _LINUX
#define EXWL_PLATFORM_LINUX
#endif

#ifdef __cplusplus
extern "C" {
#endif
	EXWLAPI ExwlWindow* exwlCreateWindow();
	EXWLAPI ex_bool exwlSetWindowSize(ExwlWindow* window, unsigned int width, unsigned int height);
	EXWLAPI void exwlSetWindowTitle(ExwlWindow* window, const char* title);
	EXWLAPI void exwlSetWindowVisible(ExwlWindow* window, ex_bool visible);

	EXWLAPI ex_bool exwlWaitWindowMessage(ExwlWindow* window);
	EXWLAPI void exwlDispatchWindowMessage(ExwlWindow* window);
#ifdef __cplusplus
}
#endif