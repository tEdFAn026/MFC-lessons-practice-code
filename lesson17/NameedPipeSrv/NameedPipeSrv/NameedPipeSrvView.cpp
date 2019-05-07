
// NameedPipeSrvView.cpp : implementation of the CNameedPipeSrvView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NameedPipeSrv.h"
#endif

#include "NameedPipeSrvDoc.h"
#include "NameedPipeSrvView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNameedPipeSrvView

IMPLEMENT_DYNCREATE(CNameedPipeSrvView, CView)

BEGIN_MESSAGE_MAP(CNameedPipeSrvView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PIPE_CREATE, &CNameedPipeSrvView::OnPipeCreate)
	ON_COMMAND(ID_PIPE_READ, &CNameedPipeSrvView::OnPipeRead)
	ON_COMMAND(ID_PIPE_WRITE, &CNameedPipeSrvView::OnPipeWrite)
END_MESSAGE_MAP()

// CNameedPipeSrvView construction/destruction

CNameedPipeSrvView::CNameedPipeSrvView()
{
	// TODO: add construction code here
	m_hPipe = NULL;
}

CNameedPipeSrvView::~CNameedPipeSrvView()
{
	if (m_hPipe) CloseHandle(m_hPipe);
}

BOOL CNameedPipeSrvView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CNameedPipeSrvView drawing

void CNameedPipeSrvView::OnDraw(CDC* /*pDC*/)
{
	CNameedPipeSrvDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CNameedPipeSrvView printing

BOOL CNameedPipeSrvView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNameedPipeSrvView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNameedPipeSrvView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CNameedPipeSrvView diagnostics

#ifdef _DEBUG
void CNameedPipeSrvView::AssertValid() const
{
	CView::AssertValid();
}

void CNameedPipeSrvView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNameedPipeSrvDoc* CNameedPipeSrvView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNameedPipeSrvDoc)));
	return (CNameedPipeSrvDoc*)m_pDocument;
}
#endif //_DEBUG


// CNameedPipeSrvView message handlers


void CNameedPipeSrvView::OnPipeCreate()
{
	// TODO: Add your command handler code here
	m_hPipe = CreateNamedPipe(L"\\\\.\\pipe\\MyPipe", PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, 0, 1, 1024, 1024, 0, NULL);
	if (INVALID_HANDLE_VALUE == m_hPipe) {
		int err = GetLastError();
		CloseHandle(m_hPipe);
		m_hPipe = NULL;
		MessageBox(L"Create pipe fail");
		return;
	}

	HANDLE hEvent;
	hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (!hEvent) {
		MessageBox(L"Create Event fail");
		CloseHandle(m_hPipe);
		m_hPipe = NULL;
		return;
	}

	OVERLAPPED ovp;
	ZeroMemory(&ovp, sizeof(OVERLAPPED));
	ovp.hEvent = hEvent;

	if (!ConnectNamedPipe(m_hPipe, &ovp)) {
		if (ERROR_IO_PENDING != GetLastError()) {
			MessageBox(L"Create connect fail");
			CloseHandle(m_hPipe);
			CloseHandle(hEvent);
			m_hPipe = NULL;
			return;
		}
	}

	if (WAIT_FAILED == WaitForSingleObject(hEvent, INFINITE)) {
		MessageBox(L"Create wait fail");
		CloseHandle(m_hPipe);
		CloseHandle(hEvent);
		m_hPipe = NULL;
		return;
	}

	CloseHandle(hEvent);
}


void CNameedPipeSrvView::OnPipeRead()
{
	// TODO: Add your command handler code here
	char chBuf[100];
	DWORD dwRead;
	ReadFile(m_hPipe, chBuf, 100, &dwRead, NULL);
	MessageBoxA(m_hWnd, chBuf, "", 0);
}


void CNameedPipeSrvView::OnPipeWrite()
{
	// TODO: Add your command handler code here
	char chBuf[] = "hello";
	DWORD dwWrite;
	WriteFile(m_hPipe, chBuf, strlen(chBuf) + 1, &dwWrite, NULL);
}
