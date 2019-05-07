
// MenuView.cpp : implementation of the CMenuView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Menu.h"
#endif

#include "MenuDoc.h"
#include "MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMenuView
#define MAX_PHONE_NUMBER 10

IMPLEMENT_DYNCREATE(CMenuView, CView)

BEGIN_MESSAGE_MAP(CMenuView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_1_1, &CMenuView::On11)
	ON_COMMAND_RANGE(IDM_Phone, IDM_Phone + MAX_PHONE_NUMBER - 1, &CMenuView::OnPhone)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMenuView construction/destruction

CMenuView::CMenuView()
	: m_iIndex(-1)
	, m_strLine(_T(""))
{
	// TODO: add construction code here
	
}

CMenuView::~CMenuView()
{
}

BOOL CMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMenuView drawing

void CMenuView::OnDraw(CDC* /*pDC*/)
{
	CMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMenuView printing

BOOL CMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMenuView diagnostics

#ifdef _DEBUG
void CMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuDoc* CMenuView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuDoc)));
	return (CMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMenuView message handlers


void CMenuView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: Add your message handler code here
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, GetParent());
}


void CMenuView::On11()
{
	// TODO: Add your command handler code here
	MessageBox(L"view show");
}


void CMenuView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);	
	switch (nChar)
	{
	case 0x0d:
		if (0 == ++m_iIndex) {
			m_menu.CreatePopupMenu();
			GetParent()->GetMenu()->AppendMenu(MF_POPUP, (UINT_PTR)m_menu.m_hMenu, L"Phone");
			GetParent()->DrawMenuBar();
		}	
		m_menu.AppendMenu(MF_STRING, IDM_Phone + m_iIndex, m_strLine.Left(m_strLine.Find(L' ')));
		m_strArrayPhone.Add(m_strLine);
		m_strLine.Empty();
		Invalidate();	
		break;
	default:
		m_strLine += (TCHAR)nChar;
		dc.TextOut(0, 0, m_strLine);
		break;
	}

	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CMenuView::OnPhone(UINT uID) {
	//CClientDC dc(this);
	//dc.TextOut(0,0, m_strArrayPhone.GetAt(0));
}
