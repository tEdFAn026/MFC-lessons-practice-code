
// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawView construction/destruction

CDrawView::CDrawView()
	: m_ptOrigin(0)
	, m_bDraw(FALSE)
	, m_ptOld(0)
{
	// TODO: add construction code here

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDrawView drawing

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDrawView printing

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView message handlers


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox(L"View clicked");
	m_ptOrigin = m_ptOld = point;
	m_bDraw = TRUE;

	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//方法1:
	//HDC hdc;
	//hdc = ::GetDC(m_hWnd);
	//MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//LineTo(hdc, point.x, point.y);
	//::ReleaseDC(m_hWnd, hdc);

	//方法2:
	//CDC* pDC = GetDC();
	//pDC->MoveTo(m_ptOrigin);
	//pDC->LineTo(point);
	//ReleaseDC(pDC);

	//方法3:
	//CClientDC dc(this);
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);

	//方法4:
	//CWindowDC wdc(this);
	//wdc.MoveTo(m_ptOrigin);
	//wdc.LineTo(point);

	//改画笔:
	//CPen pen(PS_DASH, 2, RGB(255, 0, 0));
	//CClientDC dc(this);
	//CPen *pOldPen = dc.SelectObject(&pen);
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//dc.SelectObject(pOldPen);

	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//CBrush brush(&bitmap);
	//CBrush brush(RGB(255, 0, 0));
	//CClientDC dc(this);
	//dc.FillRect(CRect(m_ptOrigin, point), &brush);
	//CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	//CBrush* pOldBrush = dc.SelectObject(pBrush);
	//dc.Rectangle(CRect(m_ptOrigin, point));
	//dc.SelectObject(pOldBrush);

	m_bDraw = FALSE;

	CView::OnLButtonUp(nFlags, point);
}


void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen pen(PS_DASH, 2, RGB(200, 0, 0));
	CPen *pOldPen = dc.SelectObject(&pen);

	if (m_bDraw) {
		//dc.SetROP2(R2_BLACK);
		//dc.MoveTo(m_ptOrigin);
		//dc.LineTo(point);
		//dc.MoveTo(m_ptOld);
		//dc.LineTo(point);
		//m_ptOld = point;

		dc.MoveTo(m_ptOrigin);
		dc.LineTo(m_ptOld);
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_ptOld = point;

		CPen pen(PS_DASH, 2, RGB(0, 255, 0));
		CPen *pOldPen = dc.SelectObject(&pen);
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		dc.SelectObject(pOldPen);
	}

	dc.SelectObject(pOldPen);

	CView::OnMouseMove(nFlags, point);
}
