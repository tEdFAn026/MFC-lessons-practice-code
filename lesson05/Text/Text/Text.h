
// Text.h : main header file for the Text application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTextApp:
// See Text.cpp for the implementation of this class
//

class CTextApp : public CWinAppEx
{
public:
	CTextApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTextApp theApp;
