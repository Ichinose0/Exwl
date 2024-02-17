/////////////////////////////////////////////////////////////////////////////
// Name:        Exwl
// Purpose:     Primary header for Exwl
// Author:      Ichinose0
// Created:     2024-02-17
/////////////////////////////////////////////////////////////////////////////

#define EXWLAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif
	EXWLAPI void exwlCreateWindow();
#ifdef __cplusplus
}
#endif