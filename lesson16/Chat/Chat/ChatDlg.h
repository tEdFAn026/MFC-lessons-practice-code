
// ChatDlg.h : header file
//
#define UM_SOCK WM_USER+26
#pragma once


// CChatDlg dialog
class CChatDlg : public CDialogEx
{
// Construction
public:
	CChatDlg(CWnd* pParent = NULL);	// standard constructor
	~CChatDlg();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT_DIALOG };
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
	afx_msg LRESULT OnSock(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	SOCKET m_socket;
public:
	BOOL InitSocket();
	afx_msg void OnBnClickedButtonSend();
};
