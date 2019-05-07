
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
	ON_COMMAND(ID_DRAW_ELLIPSE, &CGraphicView::OnDrawEllipse)
	ON_COMMAND(ID_DRAW_POINT, &CGraphicView::OnDrawPoint)
	ON_COMMAND(ID_DRAW_SQUARE, &CGraphicView::OnDrawSquare)
	ON_COMMAND(ID_DRAW_STRING, &CGraphicView::OnDrawString)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAW_SETTING, &CGraphicView::OnDrawSetting)
	ON_COMMAND(ID_DRAW_COLOR, &CGraphicView::OnDrawColor)
	ON_COMMAND(ID_DRAW_FONT, &CGraphicView::OnDrawFont)
//	ON_WM_PAINT()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CGraphicView construction/destruction

CGraphicView::CGraphicView()
	: m_nDrawType(0)
	, m_ptOrigin(0)
	, m_nLineWidth(1)
	, m_nLineType(0)
	, m_strFontName(_T(""))
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
	CFont* pPrvFont = pDC->SelectObject(&m_font);
	pDC->TextOut(0, 0, m_strFontName);
	pDC->SelectObject(pPrvFont);
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


void CGraphicView::OnDrawEllipse()
{
	// TODO: Add your command handler code here
	m_nDrawType = 4;
}


void CGraphicView::OnDrawPoint()
{
	// TODO: Add your command handler code here
	m_nDrawType = 1;
}


void CGraphicView::OnDrawSquare()
{
	// TODO: Add your command handler code here
	m_nDrawType = 3;
}


void CGraphicView::OnDrawString()
{
	// TODO: Add your command handler code here
	m_nDrawType = 2;
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
	CPen pen(m_nLineType, m_nLineWidth, m_clr);
	CPen* pPrePen = dc.SelectObject(&pen);
	CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	pBrush = dc.SelectObject(pBrush);
	switch (m_nDrawType)
	{
	case 1:
		dc.SetPixel(point, m_clr);
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

	dc.SelectObject(pPrePen);
	dc.SelectObject(pBrush);
	CView::OnLButtonUp(nFlags, point);
}

#include "CSettingDlg.h"
void CGraphicView::OnDrawSetting()
{
	// TODO: Add your command handler code here
	CSettingDlg settingDlg;
	settingDlg.m_nLineWidth = m_nLineWidth;
	settingDlg.m_nLineType = m_nLineType;
	settingDlg.m_clr = m_clr;
	settingDlg.m_pFont = &m_font;
	if (IDOK == settingDlg.DoModal()) {
		m_nLineWidth = settingDlg.m_nLineWidth;
		m_nLineType = settingDlg.m_nLineType;
	}
}


void CGraphicView::OnDrawColor()
{
	// TODO: Add your command handler code here
	CColorDialog colorDlg;
	colorDlg.m_cc.Flags |= CC_RGBINIT;
	colorDlg.m_cc.rgbResult = m_clr;
	if (IDOK == colorDlg.DoModal()) {
		m_clr = colorDlg.m_cc.rgbResult;
	}
}


void CGraphicView::OnDrawFont()
{
	// TODO: Add your command handler code here
	CFontDialog fontDlg;
	if (IDOK == fontDlg.DoModal()) {
		m_strFontName = fontDlg.m_cf.lpLogFont->lfFaceName;
		if (m_font.m_hObject)
			m_font.DeleteObject();
		m_font.CreatePointFontIndirect(fontDlg.m_cf.lpLogFont);
		Invalidate();
	}
}




BOOL CGraphicView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);

	BITMAP bmp;
	bitmap.GetBitmap(&bmp);

	CDC dcCom;
	dcCom.CreateCompatibleDC(pDC);
	dcCom.SelectObject(&bitmap);

	CRect rect;
	GetClientRect(&rect);
	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCom, 0, 0, SRCCOPY);
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCom, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
	
	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}
