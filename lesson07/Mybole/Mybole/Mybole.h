
// Mybole.h : main header file for the Mybole application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMyboleApp:
// See Mybole.cpp for the implementation of this class
//

class CMyboleApp : public CWinAppEx
{
public:
	CMyboleApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyboleApp theApp;
