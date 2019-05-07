
// ClockTestDlg.h : header file
//

#pragma once
#include "clockctrl1.h"


// CClockTestDlg dialog
class CClockTestDlg : public CDialogEx
{
// Construction
public:
	CClockTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLOCKTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CClockctrl1 m_cl;
	CClockctrl1 m_Ncl;
	DECLARE_EVENTSINK_MAP()
	void ClickClockctrl1();
};
