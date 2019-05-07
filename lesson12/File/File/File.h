
// File.h : main header file for the File application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFileApp:
// See File.cpp for the implementation of this class
//

class CFileApp : public CWinAppEx
{
public:
	CFileApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFileApp theApp;
