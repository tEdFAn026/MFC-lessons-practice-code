
// StyleView.cpp : implementation of the CStyleView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Style.h"
#endif

#include "StyleDoc.h"
#include "StyleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStyleView

IMPLEMENT_DYNCREATE(CStyleView, CView)

BEGIN_MESSAGE_MAP(CStyleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(IDM_TEST, &CStyleView::OnTest)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CStyleView construction/destruction

CStyleView::CStyleView()
{
	// TODO: add construction code here

}

CStyleView::~CStyleView()
{
}

BOOL CStyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	//cs.lpszClass = L"asdasd";

	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, LoadCursor(NULL, IDC_CROSS), (HBRUSH)GetStockObject(BLACK_BRUSH), 0);
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW);

	return CView::PreCreateWindow(cs);
}

// CStyleView drawing

void CStyleView::OnDraw(CDC* /*pDC*/)
{
	CStyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CStyleView printing

BOOL CStyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CStyleView diagnostics

#ifdef _DEBUG
void CStyleView::AssertValid() const
{
	CView::AssertValid();
}

void CStyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStyleDoc* CStyleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStyleDoc)));
	return (CStyleDoc*)m_pDocument;
}
#endif //_DEBUG


// CStyleView message handlers


int CStyleView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_CROSS));
	SetClassLong(m_hWnd, GCL_HBRBACKGROUND, (LONG)GetStockObject(BLACK_BRUSH));
	return 0;
}


void CStyleView::OnTest()
{
	// TODO: Add your command handler code here
	MessageBox(L"Test");
}

#include "MainFrm.h"
void CStyleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format(L"%d,%d", point.x, point.y);
	CMainFrame* pMainFrame = (CMainFrame*) GetParent();
	//pMainFrame->GetMessageBar()->SetWindowText(str);
	//pMainFrame->SetMessageText(str);
	GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowText(str);
	CView::OnMouseMove(nFlags, point);
}
