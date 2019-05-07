
// MailSoltCltView.cpp : implementation of the CMailSoltCltView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MailSoltClt.h"
#endif

#include "MailSoltCltDoc.h"
#include "MailSoltCltView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMailSoltCltView

IMPLEMENT_DYNCREATE(CMailSoltCltView, CView)

BEGIN_MESSAGE_MAP(CMailSoltCltView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SENDDATA, &CMailSoltCltView::OnSenddata)
END_MESSAGE_MAP()

// CMailSoltCltView construction/destruction

CMailSoltCltView::CMailSoltCltView()
{
	// TODO: add construction code here

}

CMailSoltCltView::~CMailSoltCltView()
{
}

BOOL CMailSoltCltView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMailSoltCltView drawing

void CMailSoltCltView::OnDraw(CDC* /*pDC*/)
{
	CMailSoltCltDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMailSoltCltView printing

BOOL CMailSoltCltView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMailSoltCltView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMailSoltCltView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMailSoltCltView diagnostics

#ifdef _DEBUG
void CMailSoltCltView::AssertValid() const
{
	CView::AssertValid();
}

void CMailSoltCltView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMailSoltCltDoc* CMailSoltCltView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMailSoltCltDoc)));
	return (CMailSoltCltDoc*)m_pDocument;
}
#endif //_DEBUG


// CMailSoltCltView message handlers


void CMailSoltCltView::OnSenddata()
{
	// TODO: Add your command handler code here
	HANDLE hMailSolt;
	hMailSolt = CreateFile(L"\\\\*\\mailslot\\MyMS", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hMailSolt) {
		int err = GetLastError();
		CloseHandle(hMailSolt);
		MessageBox(L"Open Fail");
		return;
	}

	char chBuf[] = "hello SRV";
	DWORD dwWrite;
	WriteFile(hMailSolt, chBuf, strlen(chBuf) + 1, &dwWrite, NULL);
	CloseHandle(hMailSolt);
}
