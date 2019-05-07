
// MailSoltSrvView.h : interface of the CMailSoltSrvView class
//

#pragma once


class CMailSoltSrvView : public CView
{
protected: // create from serialization only
	CMailSoltSrvView();
	DECLARE_DYNCREATE(CMailSoltSrvView)

// Attributes
public:
	CMailSoltSrvDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMailSoltSrvView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecvdata();
};

#ifndef _DEBUG  // debug version in MailSoltSrvView.cpp
inline CMailSoltSrvDoc* CMailSoltSrvView::GetDocument() const
   { return reinterpret_cast<CMailSoltSrvDoc*>(m_pDocument); }
#endif

