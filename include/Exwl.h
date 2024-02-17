/////////////////////////////////////////////////////////////////////////////
// Name:        Exwl
// Purpose:     Primary header for Exwl
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#pragma once

#define EXWLAPI __declspec(dllexport)

typedef struct ExwlWindow ExwlWindow;

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
#ifdef __cplusplus
}
#endif