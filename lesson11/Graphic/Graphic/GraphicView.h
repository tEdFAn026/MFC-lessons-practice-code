
// GraphicView.h : interface of the CGraphicView class
//

#pragma once
#include "atltypes.h"
#include "afxcoll.h"
#include "afxext.h"
#include "afxwin.h"


class CGraphicView : public CScrollView
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
	int m_nDrawType;
	CPoint m_ptOrigin;
	afx_msg void OnDrawDot();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRectangle();
	afx_msg void OnDrawEllipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPtrArray m_ptrArray;
	afx_msg void OnPaint();
	virtual void OnInitialUpdate();
	CMetaFileDC m_dcMetaFile;
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	CDC m_dcCom;
	CRect m_Rect;
};

#ifndef _DEBUG  // debug version in GraphicView.cpp
inline CGraphicDoc* CGraphicView::GetDocument() const
   { return reinterpret_cast<CGraphicDoc*>(m_pDocument); }
#endif

