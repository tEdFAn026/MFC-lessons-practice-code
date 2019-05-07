
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Child.h"
#endif

#include "ChildDoc.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

IMPLEMENT_DYNCREATE(CChildView, CView)

BEGIN_MESSAGE_MAP(CChildView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_NIMINGGUANDAO_READ, &CChildView::OnNimingguandaoRead)
	ON_COMMAND(ID_NIMINGGUANDAO_WRITE, &CChildView::OnNimingguandaoWrite)
END_MESSAGE_MAP()

// CChildView construction/destruction

CChildView::CChildView()
{
	// TODO: add construction code here
	m_hRead = NULL;
	m_hWrite = NULL;
}

CChildView::~CChildView()
{
	if (m_hRead) CloseHandle(m_hRead);
	if (m_hWrite) CloseHandle(m_hWrite);
}

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CChildView drawing

void CChildView::OnDraw(CDC* /*pDC*/)
{
	CChildDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CChildView printing

BOOL CChildView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChildView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChildView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CChildView diagnostics

#ifdef _DEBUG
void CChildView::AssertValid() const
{
	CView::AssertValid();
}

void CChildView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChildDoc* CChildView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChildDoc)));
	return (CChildDoc*)m_pDocument;
}
#endif //_DEBUG


// CChildView message handlers


void CChildView::OnNimingguandaoRead()
{
	// TODO: Add your command handler code here
	char chBuf[100];
	DWORD dwRead;
	ReadFile(m_hRead, chBuf, 100, &dwRead, NULL);
	MessageBoxA(m_hWnd, chBuf, "", 0);
}


void CChildView::OnNimingguandaoWrite()
{
	// TODO: Add your command handler code here
	char chBuf[] = "hello parent";
	DWORD dwWrite;
	WriteFile(m_hWrite, chBuf, strlen(chBuf) + 1, &dwWrite, NULL);
}


void CChildView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	m_hRead = GetStdHandle(STD_INPUT_HANDLE);
	m_hWrite = GetStdHandle(STD_OUTPUT_HANDLE);
}
