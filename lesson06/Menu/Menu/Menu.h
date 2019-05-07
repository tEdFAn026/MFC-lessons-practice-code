
// Menu.h : main header file for the Menu application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMenuApp:
// See Menu.cpp for the implementation of this class
//

class CMenuApp : public CWinAppEx
{
public:
	CMenuApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMenuApp theApp;
