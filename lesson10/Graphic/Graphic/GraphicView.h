
// GraphicView.h : interface of the CGraphicView class
//

#pragma once
#include "atltypes.h"
#include "afxwin.h"


class CGraphicView : public CView
{
protected: // create from serialization only
	CGraphicView();
	DECLARE_DYNCREATE(CGraphicView)

// Attributes
public:
	CGraphicDoc* GetDocument() const;

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
	virtual ~CGraphicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawPoint();
	afx_msg void OnDrawSquare();
	afx_msg void OnDrawString();
private:
	UINT m_nDrawType;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint m_ptOrigin;
	afx_msg void OnDrawSetting();
	UINT m_nLineWidth;
	int m_nLineType;
	afx_msg void OnDrawColor();
	COLORREF m_clr;
	afx_msg void OnDrawFont();
	CFont m_font;
	CString m_strFontName;
//	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // debug version in GraphicView.cpp
inline CGraphicDoc* CGraphicView::GetDocument() const
   { return reinterpret_cast<CGraphicDoc*>(m_pDocument); }
#endif

