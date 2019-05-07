
// NameedPipeSrv.h : main header file for the NameedPipeSrv application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CNameedPipeSrvApp:
// See NameedPipeSrv.cpp for the implementation of this class
//

class CNameedPipeSrvApp : public CWinAppEx
{
public:
	CNameedPipeSrvApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNameedPipeSrvApp theApp;
