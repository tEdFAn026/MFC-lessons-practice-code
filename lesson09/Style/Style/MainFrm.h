
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

#define UM_PROGRESS WM_USER+500

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:  // control bar embedded members
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CToolBar          m_newToolBar;
	CProgressCtrl	  m_progressCtrl;
// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	HICON m_HICONs[3];
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNewtool();
	afx_msg void OnUpdateNewtool(CCmdUI *pCmdUI);
	afx_msg LRESULT OnProgress(WPARAM wParam, LPARAM lParam);
	afx_msg void OnPaint();
};


