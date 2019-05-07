
// ChatDlg.h : header file
//
#define WM_RECVDATA WM_USER+26
#pragma once

struct SRecvParam
{
	SOCKET sock;
	HWND hWnd;
};
// CChatDlg dialog
class CChatDlg : public CDialogEx
{
// Construction
public:
	CChatDlg(CWnd* pParent = NULL);	// standard constructor

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
	afx_msg LRESULT OnRecvData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	BOOL InitSocket();
	static DWORD WINAPI RecvProc(LPVOID lpParameter);
private:
	SOCKET m_Socket;
public:
	afx_msg void OnBnClickedButtonSend();
};
