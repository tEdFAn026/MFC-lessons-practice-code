
// ParentView.cpp : implementation of the CParentView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Parent.h"
#endif

#include "ParentDoc.h"
#include "ParentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CParentView

IMPLEMENT_DYNCREATE(CParentView, CView)

BEGIN_MESSAGE_MAP(CParentView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_NIMINGGUANDAO_CREATE, &CParentView::OnNimingguandaoCreate)
	ON_COMMAND(ID_NIMINGGUANDAO_READ, &CParentView::OnNimingguandaoRead)
	ON_COMMAND(ID_NIMINGGUANDAO_WRITE, &CParentView::OnNimingguandaoWrite)
END_MESSAGE_MAP()

// CParentView construction/destruction

CParentView::CParentView()
{
	// TODO: add construction code here
	m_hRead = NULL;
	m_hWrite = NULL;
}

CParentView::~CParentView()
{
	if (m_hRead) CloseHandle(m_hRead);
	if (m_hWrite) CloseHandle(m_hWrite);
}

BOOL CParentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CParentView drawing

void CParentView::OnDraw(CDC* /*pDC*/)
{
	CParentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CParentView printing

BOOL CParentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CParentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CParentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CParentView diagnostics

#ifdef _DEBUG
void CParentView::AssertValid() const
{
	CView::AssertValid();
}

void CParentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CParentDoc* CParentView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CParentDoc)));
	return (CParentDoc*)m_pDocument;
}
#endif //_DEBUG


// CParentView message handlers


void CParentView::OnNimingguandaoCreate()
{
	// TODO: Add your command handler code here
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	if (!CreatePipe(&m_hRead, &m_hWrite, &sa, 0)) {
		MessageBox(L"Create fail!");
		return;
	}

#ifdef DEBUG
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;
	ZeroMemory(&sui, sizeof(STARTUPINFO));
	sui.cb = sizeof(STARTUPINFO);
	sui.dwFlags = STARTF_USESTDHANDLES;
	sui.hStdInput = m_hRead;
	sui.hStdOutput = m_hWrite;
	sui.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	if (!CreateProcess(L"..\\Debug\\Child.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi)) {
		int err = GetLastError();
		CloseHandle(m_hRead);
		CloseHandle(m_hWrite);
		m_hRead = NULL;
		m_hWrite = NULL;
		MessageBox(L"Create sub Process fail!");
	}
	else {
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
#endif // DEBUG
}


void CParentView::OnNimingguandaoRead()
{
	// TODO: Add your command handler code here
	char chBuf[100];
	DWORD dwRead;
	ReadFile(m_hRead, chBuf, 100, &dwRead, NULL);
	MessageBoxA(m_hWnd,chBuf,"",0);
}


void CParentView::OnNimingguandaoWrite()
{
	// TODO: Add your command handler code here
	char chBuf[]="hello";
	DWORD dwWrite;
	WriteFile(m_hWrite, chBuf, strlen(chBuf) + 1, &dwWrite, NULL);
}
