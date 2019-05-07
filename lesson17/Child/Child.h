
// Child.h : main header file for the Child application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CChildApp:
// See Child.cpp for the implementation of this class
//

class CChildApp : public CWinAppEx
{
public:
	CChildApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CChildApp theApp;
