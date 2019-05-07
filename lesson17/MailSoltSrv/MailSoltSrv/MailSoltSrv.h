
// MailSoltSrv.h : main header file for the MailSoltSrv application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMailSoltSrvApp:
// See MailSoltSrv.cpp for the implementation of this class
//

class CMailSoltSrvApp : public CWinAppEx
{
public:
	CMailSoltSrvApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMailSoltSrvApp theApp;
