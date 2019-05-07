
// MenuView.h : interface of the CMenuView class
//

#pragma once
#include "afxwin.h"
#include "afxcoll.h"


class CMenuView : public CView
{
protected: // create from serialization only
	CMenuView();
	DECLARE_DYNCREATE(CMenuView)

// Attributes
public:
	CMenuDoc* GetDocument() const;

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
	virtual ~CMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void On11();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPhone(UINT uID);
private:
	int m_iIndex;
	CMenu m_menu;
public:
	CString m_strLine;
	CStringArray m_strArrayPhone;
};

#ifndef _DEBUG  // debug version in MenuView.cpp
inline CMenuDoc* CMenuView::GetDocument() const
   { return reinterpret_cast<CMenuDoc*>(m_pDocument); }
#endif

