
// MailSoltCltView.h : interface of the CMailSoltCltView class
//

#pragma once


class CMailSoltCltView : public CView
{
protected: // create from serialization only
	CMailSoltCltView();
	DECLARE_DYNCREATE(CMailSoltCltView)

// Attributes
public:
	CMailSoltCltDoc* GetDocument() const;

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
	virtual ~CMailSoltCltView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSenddata();
};

#ifndef _DEBUG  // debug version in MailSoltCltView.cpp
inline CMailSoltCltDoc* CMailSoltCltView::GetDocument() const
   { return reinterpret_cast<CMailSoltCltDoc*>(m_pDocument); }
#endif

