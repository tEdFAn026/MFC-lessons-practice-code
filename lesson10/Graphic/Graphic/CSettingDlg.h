#pragma once
#include "afxwin.h"
#include "TestBtn.h"


// DSettingDlg dialog

class CSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSettingDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	UINT m_nLineWidth;
	int m_nLineType;
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEditLineWidth();
	afx_msg void OnSelchangeComboLinetype();
	afx_msg void OnPaint();
	COLORREF m_clr;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBrush m_brush;
	CFont* m_pFont;
	CTestBtn m_btnOKTest;
};
