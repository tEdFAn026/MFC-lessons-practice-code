
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Menu.h"

#include "MainFrm.h"
#include "MenuDoc.h"
#include "MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(IDM_TEST, &CMainFrame::OnTest)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CMainFrame::OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, &CMainFrame::OnUpdateFileNew)
	ON_COMMAND(ID_1_1, &CMainFrame::On11)
	ON_COMMAND(IDM_HELLO, &CMainFrame::OnHello)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	//m_bAutoMenuEnable = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);
	GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_BYCOMMAND | MF_CHECKED);

	//GetMenu()->GetSubMenu(0)->SetDefaultItem(1, TRUE);
	GetMenu()->GetSubMenu(0)->SetDefaultItem(ID_FILE_OPEN);

	//CString str;
	//str.Format(L"x=%d,y=%d\n", GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CXMENUCHECK));
	//MessageBox(str);

	m_bitMap.LoadBitmapW(IDB_BITMAP1);
	GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &m_bitMap, &m_bitMap);
	GetMenu()->GetSubMenu(0)->EnableMenuItem(2, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);

	//SetMenu(NULL);

	CMenu menu;
	//menu.LoadMenuW(IDR_MAINFRAME);
	menu.CreatePopupMenu();
	//GetMenu()->AppendMenu(MF_POPUP, (UINT_PTR)menu.m_hMenu, L"aa");
	GetMenu()->InsertMenu(2, MF_BYPOSITION | MF_POPUP, (UINT_PTR)menu.m_hMenu, L"aa");
	menu.AppendMenu(MF_STRING, IDM_HELLO, L"HELLO");
	menu.AppendMenu(MF_STRING, 112, L"HELLO2");
	menu.AppendMenu(MF_STRING, 113, L"HELLO3");
	GetMenu()->GetSubMenu(0)->AppendMenu(MF_STRING, 114, L"WE");
	GetMenu()->GetSubMenu(0)->InsertMenu(2, MF_BYPOSITION | MF_POPUP, 15, L"aaa");
	GetMenu()->DeleteMenu(1, MF_BYPOSITION);
	GetMenu()->GetSubMenu(0)->DeleteMenu(1, MF_BYPOSITION);
	//SetMenu(&menu);
	menu.Detach();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers



void CMainFrame::OnTest()
{
	// TODO: Add your command handler code here
	MessageBox(L"test");
}


void CMainFrame::OnUpdateEditCut(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}


void CMainFrame::OnUpdateFileNew(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	//if (ID_FILE_NEW == pCmdUI->m_nID)
		pCmdUI->Enable(FALSE);
}


void CMainFrame::On11()
{
	// TODO: Add your command handler code here
	MessageBox(L"Main show");
}


void CMainFrame::OnHello()
{
	// TODO: Add your command handler code here
	MessageBox(L"Hello"); 
}

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your specialized code here and/or call the base class
	int iMenuID = LOWORD(wParam);
	CMenuView* pView = (CMenuView*)GetActiveView();
	if (iMenuID >= IDM_Phone && iMenuID < IDM_Phone + pView->m_strArrayPhone.GetSize()) {
		CClientDC dc(pView);
		dc.TextOut(0, 0, pView->m_strArrayPhone.GetAt(iMenuID - IDM_Phone));
		return TRUE;
	}	

	return CFrameWnd::OnCommand(wParam, lParam);
}
