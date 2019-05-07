
// FileView.h : interface of the CFileView class
//

#pragma once


class CFileView : public CView
{
protected: // create from serialization only
	CFileView();
	DECLARE_DYNCREATE(CFileView)

// Attributes
public:
	CFileDoc* GetDocument() const;

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
	virtual ~CFileView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWenjianDuqu();
	afx_msg void OnWenjianXieru();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	afx_msg void OnRegRead();
	afx_msg void OnRegWrite();
};

#ifndef _DEBUG  // debug version in FileView.cpp
inline CFileDoc* CFileView::GetDocument() const
   { return reinterpret_cast<CFileDoc*>(m_pDocument); }
#endif

