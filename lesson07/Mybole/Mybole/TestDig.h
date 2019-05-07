#pragma once
#include "afxwin.h"


// CTestDig dialog

class CTestDig : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDig)

public:
	CTestDig(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTestDig();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedStaticNumber1();
public:
	CButton m_btnAdd;
	int m_iNum1;
	int m_iNum2;
	int m_iNum3;
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
