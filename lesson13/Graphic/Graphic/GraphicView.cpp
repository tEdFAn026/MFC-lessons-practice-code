
// GraphicView.cpp : implementation of the CGraphicView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Graphic.h"
#endif

#include "GraphicDoc.h"
#include "GraphicView.h"
#include "Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicView

IMPLEMENT_DYNCREATE(CGraphicView, CView)

BEGIN_MESSAGE_MAP(CGraphicView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_WENJIAN_DUQU, &CGraphicView::OnWenjianDuqu)
	ON_COMMAND(ID_WENJIAN_XIERU, &CGraphicView::OnWenjianXieru)
	ON_COMMAND(IDM_DRAW_DOT, &CGraphicView::OnDrawDot)
	ON_COMMAND(IDM_DRAW_LINE, &CGraphicView::OnDrawLine)
	ON_COMMAND(IDM_DRAW_RECT, &CGraphicView::OnDrawRect)
	ON_COMMAND(IDM_DRAW_ELLIPSE, &CGraphicView::OnDrawEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CGraphicView construction/destruction

CGraphicView::CGraphicView()
	: m_nDrawType(0)
	, m_ptOrigin(0)
{
	// TODO: add construction code here

}

CGraphicView::~CGraphicView()
{
}

BOOL CGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGraphicView drawing

void CGraphicView::OnDraw(CDC* pDC)
{
	CGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	int size = pDoc->m_obArray.GetSize();
	for (int i = 0; i < size; i++)
	{
		((CGraph*)pDoc->m_obArray.GetAt(i))->Draw(pDC);
	}
}


// CGraphicView printing

BOOL CGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CGraphicView diagnostics

#ifdef _DEBUG
void CGraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicDoc* CGraphicView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicDoc)));
	return (CGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicView message handlers


void CGraphicView::OnWenjianDuqu()
{
	// TODO: Add your command handler code here
	CFile file(L"1.txt", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	int i;
	char ch;
	float f;
	CString str;
	ar >> i >> ch >> f >> str;

	CString strRes;
	strRes.Format(L"%d,%c,%f,%s", i, ch, f, str);
	MessageBox(strRes);
}


void CGraphicView::OnWenjianXieru()
{
	// TODO: Add your command handler code here
	CFile file(L"1.txt", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	int i = 4;
	char ch = 'a';
	float f = 1.3f;
	CString str(L"Hello");
	ar << i << ch << f << str;
}


void CGraphicView::OnDrawDot()
{
	// TODO: Add your command handler code here
	m_nDrawType = 1;
}


void CGraphicView::OnDrawLine()
{
	// TODO: Add your command handler code here
	m_nDrawType = 2;
}


void CGraphicView::OnDrawRect()
{
	// TODO: Add your command handler code here
	m_nDrawType = 3;
}


void CGraphicView::OnDrawEllipse()
{
	// TODO: Add your command handler code here
	m_nDrawType = 4;
}


void CGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}


void CGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	pBrush = dc.SelectObject(pBrush);
	switch (m_nDrawType)
	{
	case 1:
		dc.SetPixel(point, RGB(200, 0, 128));
		break;
	case 2:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 3:
		dc.Rectangle(CRect(m_ptOrigin, point));
		break;
	case 4:
		dc.Ellipse(CRect(m_ptOrigin, point));
		break;
	default:
		break;
	}
	CGraph *pGraph = new CGraph(m_nDrawType, m_ptOrigin, point);
	GetDocument()->
	m_obArray.Add(pGraph);
	CView::OnLButtonUp(nFlags, point);
}
