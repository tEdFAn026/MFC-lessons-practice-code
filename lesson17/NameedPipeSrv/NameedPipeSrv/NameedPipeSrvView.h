
// NameedPipeSrvView.h : interface of the CNameedPipeSrvView class
//

#pragma once


class CNameedPipeSrvView : public CView
{
protected: // create from serialization only
	CNameedPipeSrvView();
	DECLARE_DYNCREATE(CNameedPipeSrvView)

// Attributes
public:
	CNameedPipeSrvDoc* GetDocument() const;

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
	virtual ~CNameedPipeSrvView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPipeCreate();
	afx_msg void OnPipeRead();
	afx_msg void OnPipeWrite();
private:
	HANDLE m_hPipe;
};

#ifndef _DEBUG  // debug version in NameedPipeSrvView.cpp
inline CNameedPipeSrvDoc* CNameedPipeSrvView::GetDocument() const
   { return reinterpret_cast<CNameedPipeSrvDoc*>(m_pDocument); }
#endif

