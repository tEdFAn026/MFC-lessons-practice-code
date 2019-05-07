
// MailSoltSrvView.cpp : implementation of the CMailSoltSrvView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MailSoltSrv.h"
#endif

#include "MailSoltSrvDoc.h"
#include "MailSoltSrvView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMailSoltSrvView

IMPLEMENT_DYNCREATE(CMailSoltSrvView, CView)

BEGIN_MESSAGE_MAP(CMailSoltSrvView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_RECVDATA, &CMailSoltSrvView::OnRecvdata)
END_MESSAGE_MAP()

// CMailSoltSrvView construction/destruction

CMailSoltSrvView::CMailSoltSrvView()
{
	// TODO: add construction code here

}

CMailSoltSrvView::~CMailSoltSrvView()
{
}

BOOL CMailSoltSrvView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMailSoltSrvView drawing

void CMailSoltSrvView::OnDraw(CDC* /*pDC*/)
{
	CMailSoltSrvDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMailSoltSrvView printing

BOOL CMailSoltSrvView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMailSoltSrvView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMailSoltSrvView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMailSoltSrvView diagnostics

#ifdef _DEBUG
void CMailSoltSrvView::AssertValid() const
{
	CView::AssertValid();
}

void CMailSoltSrvView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMailSoltSrvDoc* CMailSoltSrvView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMailSoltSrvDoc)));
	return (CMailSoltSrvDoc*)m_pDocument;
}
#endif //_DEBUG


// CMailSoltSrvView message handlers


void CMailSoltSrvView::OnRecvdata()
{
	// TODO: Add your command handler code here
	HANDLE hMailSolt;
	hMailSolt = CreateMailslot(L"\\\\.\\mailslot\\MyMS", 0, MAILSLOT_WAIT_FOREVER, NULL);
	if (INVALID_HANDLE_VALUE == hMailSolt) {
		int err = GetLastError();
		CloseHandle(hMailSolt);
		MessageBox(L"Create Fail");
		return;
	}

	char chBuf[100];
	DWORD dwRead;
	ReadFile(hMailSolt, chBuf, 100, &dwRead, NULL);
	MessageBoxA(m_hWnd, chBuf, "", 0);
	CloseHandle(hMailSolt);
}
