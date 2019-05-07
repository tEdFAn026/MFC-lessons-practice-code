
// MyboleView.cpp : implementation of the CMyboleView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Mybole.h"
#endif

#include "MyboleDoc.h"
#include "MyboleView.h"
#include "TestDig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyboleView

IMPLEMENT_DYNCREATE(CMyboleView, CView)

BEGIN_MESSAGE_MAP(CMyboleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_TESTDIG, &CMyboleView::OnTestdig)
END_MESSAGE_MAP()

// CMyboleView construction/destruction

CMyboleView::CMyboleView()
{
	// TODO: add construction code here

}

CMyboleView::~CMyboleView()
{
}

BOOL CMyboleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMyboleView drawing

void CMyboleView::OnDraw(CDC* /*pDC*/)
{
	CMyboleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMyboleView printing

BOOL CMyboleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyboleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyboleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMyboleView diagnostics

#ifdef _DEBUG
void CMyboleView::AssertValid() const
{
	CView::AssertValid();
}

void CMyboleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyboleDoc* CMyboleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyboleDoc)));
	return (CMyboleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyboleView message handlers


void CMyboleView::OnTestdig()
{
	// TODO: Add your command handler code here
	//创建模态对话框
	CTestDig dlg;
	dlg.DoModal();

	//创建非模态对话框
	//CTestDig* pdlg = new CTestDig();
	//pdlg->Create(IDD_DIALOG1,this);
	//pdlg->ShowWindow(SW_SHOWNORMAL);
}
