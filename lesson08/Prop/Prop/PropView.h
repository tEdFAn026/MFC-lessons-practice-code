
// PropView.h : interface of the CPropView class
//

#pragma once


class CPropView : public CView
{
protected: // create from serialization only
	CPropView();
	DECLARE_DYNCREATE(CPropView)

// Attributes
public:
	CPropDoc* GetDocument() const;

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
	virtual ~CPropView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPropsheet();

private:
	int m_iOccupation;
	CString m_strWorkAddr;
	BOOL m_bCheck[3];
	CString m_strMoney;
};

#ifndef _DEBUG  // debug version in PropView.cpp
inline CPropDoc* CPropView::GetDocument() const
   { return reinterpret_cast<CPropDoc*>(m_pDocument); }
#endif

