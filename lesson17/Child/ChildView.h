
// ChildView.h : interface of the CChildView class
//

#pragma once


class CChildView : public CView
{
protected: // create from serialization only
	CChildView();
	DECLARE_DYNCREATE(CChildView)

// Attributes
public:
	CChildDoc* GetDocument() const;

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
	virtual ~CChildView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNimingguandaoRead();
	afx_msg void OnNimingguandaoWrite();
	virtual void OnInitialUpdate();
private:
	HANDLE m_hRead;
	HANDLE m_hWrite;
};

#ifndef _DEBUG  // debug version in ChildView.cpp
inline CChildDoc* CChildView::GetDocument() const
   { return reinterpret_cast<CChildDoc*>(m_pDocument); }
#endif

