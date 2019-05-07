
// TextView.cpp : implementation of the CTextView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Text.h"
#endif

#include "TextDoc.h"
#include "TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextView

IMPLEMENT_DYNCREATE(CTextView, CView)

BEGIN_MESSAGE_MAP(CTextView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CTextView construction/destruction

CTextView::CTextView()
	: m_strText(_T("")), m_cpTextPos(0)
	, m_iTextBlockWidth(0)
{
	// TODO: add construction code here
	m_bmCaret.LoadBitmapW(IDB_BITMAP1);
}

CTextView::~CTextView()
{
}

BOOL CTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTextView drawing

void CTextView::OnDraw(CDC* pDC)
{
	CTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CString str(L"text");
	pDC->TextOutW(50, 50, str);
	CSize size = pDC->GetTextExtent(str);

	str.LoadStringW(IDS_TED);
	pDC->TextOutW(50, 200, str);

	pDC->BeginPath();
	pDC->Rectangle(50, 50, 50 + size.cx, 50 + size.cy);
	pDC->EndPath();
	pDC->SelectClipPath(RGN_DIFF);
	for (int i = 0; i < 300; i += 10) {
		pDC->MoveTo(0, i);
		pDC->LineTo(300, i);

		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 300);
	}
}


// CTextView printing

BOOL CTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTextView diagnostics

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextDoc* CTextView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextDoc)));
	return (CTextDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextView message handlers


int CTextView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	//CreateSolidCaret(2, tm.tmHeight);
	//ShowCaret();

	CreateCaret(&m_bmCaret);
	ShowCaret();

	SetTimer(1, 100, NULL);

	return 0;
}


void CTextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(300, L"monofur", NULL);
	CFont* pOdlFont = dc.SelectObject(&font);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	switch (nChar)
	{
	case 0x0d:
		m_strText.Empty();
		m_cpTextPos.y += tm.tmHeight + 1;
		break;
	case 0x08: {
			COLORREF clr = dc.SetTextColor(dc.GetBkColor());
			dc.TextOutW(m_cpTextPos.x, m_cpTextPos.y, m_strText);
			m_strText = m_strText.Left(m_strText.GetLength() - 1);
			dc.SetTextColor(clr);
		}
		break;
	default:
		m_strText += (TCHAR)nChar;
		break;
	}

	CSize size = dc.GetTextExtent(m_strText);
	CPoint pt(m_cpTextPos.x + size.cx, m_cpTextPos.y);
	SetCaretPos(pt);

	dc.TextOutW(m_cpTextPos.x, m_cpTextPos.y, m_strText);
	dc.SelectObject(pOdlFont);
	//dc.SelectClipPath(RGN_DIFF);
	//dc.BeginPath();
	//dc.Rectangle(m_cpTextPos.x, m_cpTextPos.y, m_cpTextPos.x + size.cx, m_cpTextPos.y + size.cy);
	//dc.EndPath();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CTextView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SetCaretPos(point);
	m_strText.Empty();
	m_cpTextPos = point;

	CView::OnLButtonDown(nFlags, point);
}


void CTextView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	//if (nIDEvent = 1) {
	m_iTextBlockWidth += 5;
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CRect rect(50,200, m_iTextBlockWidth, 200+ tm.tmHeight);

	dc.SetTextColor(RGB(255, 0, 0));
	CString str;
	str.LoadStringW(IDS_TED);
	str += L"aaaaaaa";
	dc.DrawText(str, rect, DT_LEFT);

	CSize size = dc.GetTextExtent(str);
	if (m_iTextBlockWidth > size.cx) {
		m_iTextBlockWidth = 0;
		dc.SetTextColor(RGB(0, 255, 0));
		dc.TextOutW(50, 200, str);
	}
	//}
	CView::OnTimer(nIDEvent);
}
