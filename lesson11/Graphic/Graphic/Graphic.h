
// Graphic.h : main header file for the Graphic application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGraphicApp:
// See Graphic.cpp for the implementation of this class
//

class CGraphicApp : public CWinApp
{
public:
	CGraphicApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGraphicApp theApp;
