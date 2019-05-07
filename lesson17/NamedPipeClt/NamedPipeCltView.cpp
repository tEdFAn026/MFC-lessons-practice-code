
// NamedPipeCltView.cpp : implementation of the CNamedPipeCltView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NamedPipeClt.h"
#endif

#include "NamedPipeCltDoc.h"
#include "NamedPipeCltView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNamedPipeCltView

IMPLEMENT_DYNCREATE(CNamedPipeCltView, CView)

BEGIN_MESSAGE_MAP(CNamedPipeCltView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PIPE_READ, &CNamedPipeCltView::OnPipeRead)
	ON_COMMAND(ID_PIPE_WRITE, &CNamedPipeCltView::OnPipeWrite)
	ON_COMMAND(ID_PIPE_CONNECT, &CNamedPipeCltView::OnPipeConnect)
END_MESSAGE_MAP()

// CNamedPipeCltView construction/destruction

CNamedPipeCltView::CNamedPipeCltView()
{
	// TODO: add construction code here
	m_hPipe = NULL;
}

CNamedPipeCltView::~CNamedPipeCltView()
{
	if (m_hPipe) CloseHandle(m_hPipe);
}

BOOL CNamedPipeCltView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CNamedPipeCltView drawing

void CNamedPipeCltView::OnDraw(CDC* /*pDC*/)
{
	CNamedPipeCltDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CNamedPipeCltView printing

BOOL CNamedPipeCltView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNamedPipeCltView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNamedPipeCltView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CNamedPipeCltView diagnostics

#ifdef _DEBUG
void CNamedPipeCltView::AssertValid() const
{
	CView::AssertValid();
}

void CNamedPipeCltView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNamedPipeCltDoc* CNamedPipeCltView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNamedPipeCltDoc)));
	return (CNamedPipeCltDoc*)m_pDocument;
}
#endif //_DEBUG


// CNamedPipeCltView message handlers


void CNamedPipeCltView::OnPipeRead()
{
	// TODO: Add your command handler code here
	char chBuf[100];
	DWORD dwRead;
	ReadFile(m_hPipe, chBuf, 100, &dwRead, NULL);
	MessageBoxA(m_hWnd, chBuf, "", 0);
}


void CNamedPipeCltView::OnPipeWrite()
{
	// TODO: Add your command handler code here
	char chBuf[] = "hello SRV";
	DWORD dwWrite;
	WriteFile(m_hPipe, chBuf, strlen(chBuf) + 1, &dwWrite, NULL);
}


void CNamedPipeCltView::OnPipeConnect()
{
	// TODO: Add your command handler code here
	if (!WaitNamedPipe(L"\\\\.\\pipe\\MyPipe", NMPWAIT_WAIT_FOREVER)) {
		MessageBox(L"No Pipe!");
		return;
	}

	m_hPipe = CreateFile(L"\\\\.\\pipe\\MyPipe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == m_hPipe) {
		MessageBox(L"Open Pipe fail!");
		CloseHandle(m_hPipe);
		m_hPipe = NULL;
		return;
	}
}
