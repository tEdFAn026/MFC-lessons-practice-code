
// MyboleView.h : interface of the CMyboleView class
//

#pragma once


class CMyboleView : public CView
{
protected: // create from serialization only
	CMyboleView();
	DECLARE_DYNCREATE(CMyboleView)

// Attributes
public:
	CMyboleDoc* GetDocument() const;

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
	virtual ~CMyboleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestdig();
};

#ifndef _DEBUG  // debug version in MyboleView.cpp
inline CMyboleDoc* CMyboleView::GetDocument() const
   { return reinterpret_cast<CMyboleDoc*>(m_pDocument); }
#endif

