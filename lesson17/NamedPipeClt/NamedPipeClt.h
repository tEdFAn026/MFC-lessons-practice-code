
// NamedPipeClt.h : main header file for the NamedPipeClt application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CNamedPipeCltApp:
// See NamedPipeClt.cpp for the implementation of this class
//

class CNamedPipeCltApp : public CWinAppEx
{
public:
	CNamedPipeCltApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNamedPipeCltApp theApp;
