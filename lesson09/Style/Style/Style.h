
// Style.h : main header file for the Style application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CStyleApp:
// See Style.cpp for the implementation of this class
//

class CStyleApp : public CWinAppEx
{
public:
	CStyleApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStyleApp theApp;
