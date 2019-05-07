
// NamedPipeCltView.h : interface of the CNamedPipeCltView class
//

#pragma once


class CNamedPipeCltView : public CView
{
protected: // create from serialization only
	CNamedPipeCltView();
	DECLARE_DYNCREATE(CNamedPipeCltView)

// Attributes
public:
	CNamedPipeCltDoc* GetDocument() const;

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
	virtual ~CNamedPipeCltView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPipeRead();
	afx_msg void OnPipeWrite();
	afx_msg void OnPipeConnect();
private:
	HANDLE m_hPipe;
};

#ifndef _DEBUG  // debug version in NamedPipeCltView.cpp
inline CNamedPipeCltDoc* CNamedPipeCltView::GetDocument() const
   { return reinterpret_cast<CNamedPipeCltDoc*>(m_pDocument); }
#endif

