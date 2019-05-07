
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

IMPLEMENT_DYNCREATE(CGraphicView, CScrollView)

BEGIN_MESSAGE_MAP(CGraphicView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_DRAW_DOT, &CGraphicView::OnDrawDot)
	ON_COMMAND(ID_DRAW_LINE, &CGraphicView::OnDrawLine)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CGraphicView::OnDrawRectangle)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CGraphicView::OnDrawEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_SAVE, &CGraphicView::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CGraphicView::OnFileOpen)
END_MESSAGE_MAP()

// CGraphicView construction/destruction

CGraphicView::CGraphicView()
	: m_nDrawType(0)
	, m_ptOrigin(0)
{
	// TODO: add construction code here
	m_dcMetaFile.Create();
}

CGraphicView::~CGraphicView()
{
}

BOOL CGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CGraphicView drawing

void CGraphicView::OnDraw(CDC* pDC)
{
	CGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	//CPen pen(PS_SOLID, 0, RGB(200, 0, 128));
	//CPen* pPrePen = pDC->SelectObject(&pen);
	//CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	//pBrush = pDC->SelectObject(pBrush);

	//for (size_t i = 0; i < m_ptrArray.GetSize(); i++)
	//{
	//	CGraph* p = (CGraph*) m_ptrArray.GetAt(i);
	//	if(!p)
	//		continue;

	//	switch (p->m_nDrawType)
	//	{
	//	case 1:
	//		pDC->SetPixel(p->m_ptEnd, RGB(200, 0, 128));
	//		break;
	//	case 2:
	//		pDC->MoveTo(p->m_ptOr);
	//		pDC->LineTo(p->m_ptEnd);
	//		break;
	//	case 3:
	//		pDC->Rectangle(CRect(p->m_ptOr, p->m_ptEnd));
	//		break;
	//	case 4:
	//		pDC->Ellipse(CRect(p->m_ptOr, p->m_ptEnd));
	//		break;
	//	default:
	//		break;
	//	}
	//}
	//
	//pDC->SelectObject(pPrePen);
	//pDC->SelectObject(pBrush);

	//HMETAFILE hMetaFile = m_dcMetaFile.Close();
	//pDC->PlayMetaFile(hMetaFile);
	//m_dcMetaFile.Create();
	//m_dcMetaFile.PlayMetaFile(hMetaFile);
	//DeleteMetaFile(hMetaFile);

	CRect rect;
	GetClientRect(&rect);

	//if (m_dcCom) {
	//	CBitmap bitMap;
	//	bitMap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//	CBitmap* pPrvBitMap = m_dcCom.SelectObject(&bitMap);
	//	CSize size = pPrvBitMap->GetBitmapDimension();
	//	m_dcCom.SelectObject(pPrvBitMap);
		pDC->BitBlt(0, 0, m_Rect.Width(), m_Rect.Height(), &m_dcCom, 0, 0, SRCCOPY);
	//}
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
	CScrollView::AssertValid();
}

void CGraphicView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGraphicDoc* CGraphicView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicDoc)));
	return (CGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicView message handlers


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


void CGraphicView::OnDrawRectangle()
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
	CScrollView::OnLButtonDown(nFlags, point);
}

//#define dc m_dcMetaFile
#define dc m_dcCom
void CGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//m_dcMetaFile
	CClientDC dcA(this);
	OnPrepareDC(&dcA);
	dcA.DPtoLP(&m_ptOrigin);
	dcA.DPtoLP(&point);

	//m_dcCom
	if (!m_dcCom.m_hDC)
		m_dcCom.CreateCompatibleDC(&dcA);
	CRect rect;
	GetClientRect(&rect);
	if (m_Rect.Height() < rect.Height() || m_Rect.Width() < rect.Width()) {
		m_Rect = rect;
		CBitmap bitMap;
		bitMap.CreateCompatibleBitmap(&dcA, m_Rect.Width(), m_Rect.Height());
		m_dcCom.SelectObject(bitMap);
		m_dcCom.BitBlt(0, 0, m_Rect.Width(), m_Rect.Height(), &dcA, 0, 0, SRCCOPY);
		SetScrollSizes(MM_TEXT, m_Rect.Size());
	}


	//CClientDC dc(this);
	CPen pen(PS_SOLID, 0, RGB(200,0,128));
	CPen* pPrePen = dc.SelectObject(&pen);
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
	//OnPrepareDC(&dc);
	//dc.DPtoLP(&m_ptOrigin);
	//dc.DPtoLP(&point);
	//CGraph *pGraph = new CGraph(m_nDrawType, m_ptOrigin, point); 
	//m_ptrArray.Add(pGraph);

	dc.SelectObject(pPrePen);
	dc.SelectObject(pBrush);
	Invalidate();
	CScrollView::OnLButtonUp(nFlags, point);
}
#undef dc

void CGraphicView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CScrollView::OnPaint() for painting messages
	OnPrepareDC(&dc);
	OnDraw(&dc);
}


void CGraphicView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	GetClientRect(&m_Rect);
	SetScrollSizes(MM_TEXT, m_Rect.Size());
}


void CGraphicView::OnFileSave()
{
	// TODO: Add your command handler code here
	HMETAFILE hMetaFile = m_dcMetaFile.Close();
	CopyMetaFile(hMetaFile,L"meta.wmf");
	m_dcMetaFile.Create();
	m_dcMetaFile.PlayMetaFile(hMetaFile);
	DeleteMetaFile(hMetaFile);
}


void CGraphicView::OnFileOpen()
{
	// TODO: Add your command handler code here
	HMETAFILE hMetaFile = GetMetaFile(L"meta.wmf");
	m_dcMetaFile.Close();
	m_dcMetaFile.Create();
	m_dcMetaFile.PlayMetaFile(hMetaFile); 
	DeleteMetaFile(hMetaFile);
	Invalidate();
}
