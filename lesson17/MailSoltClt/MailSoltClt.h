
// MailSoltClt.h : main header file for the MailSoltClt application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMailSoltCltApp:
// See MailSoltClt.cpp for the implementation of this class
//

class CMailSoltCltApp : public CWinAppEx
{
public:
	CMailSoltCltApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMailSoltCltApp theApp;
