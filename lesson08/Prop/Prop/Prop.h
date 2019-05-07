
// Prop.h : main header file for the Prop application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPropApp:
// See Prop.cpp for the implementation of this class
//

class CPropApp : public CWinApp
{
public:
	CPropApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPropApp theApp;
