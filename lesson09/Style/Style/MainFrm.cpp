
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Style.h"

#include "MainFrm.h"

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
	ON_WM_TIMER()
	ON_COMMAND(IDM_NEWTOOL, &CMainFrame::OnNewtool)
	ON_UPDATE_COMMAND_UI(IDM_NEWTOOL, &CMainFrame::OnUpdateNewtool)
	ON_MESSAGE(UM_PROGRESS, &CMainFrame::OnProgress)
	ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	IDS_TIME,
	IDS_PROGRESS,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

extern CStyleApp theApp;
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

	//LONG style = GetWindowLong(m_hWnd, GWL_STYLE);
	//SetWindowLong(m_hWnd, GWL_STYLE, style&~WS_MAXIMIZEBOX);

	SetClassLong(m_hWnd, GCL_HICON, (LONG)LoadIcon(NULL, IDI_ERROR));

	m_HICONs[0] = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	m_HICONs[1] = LoadIcon(theApp.m_hInstance, MAKEINTRESOURCE(IDI_ICON2));
	m_HICONs[2] = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3));

	SetClassLong(m_hWnd, GCL_HICON, (LONG)m_HICONs[0]);

	SetTimer(1, 1000, NULL);


	if (!m_newToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_newToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_newToolBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_newToolBar);


	CTime t = CTime::GetCurrentTime();
	CString str = t.Format(L"%H:%M:%S");
	CClientDC dc(this);
	CSize timeSize = dc.GetTextExtent(str);
	m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(IDS_TIME), IDS_TIME, SBPS_NORMAL, timeSize.cx);
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(IDS_TIME), str);

	PostMessage(UM_PROGRESS);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	//cs.cx = 200;
	//cs.cy = 300;
	//cs.style &= ~FWS_ADDTOTITLE;
	//cs.lpszName = L"adasda";
	//WNDCLASS wndclass;
	//wndclass.cbClsExtra = 0;
	//wndclass.cbWndExtra = 0;
	//wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//wndclass.hCursor = LoadCursor(NULL, IDC_HELP);
	//wndclass.hIcon = LoadIcon(NULL,IDI_ERROR);
	//wndclass.hInstance = AfxGetInstanceHandle();
	//wndclass.lpfnWndProc = ::DefWindowProc;
	//wndclass.lpszClassName = L"asdasd";
	//wndclass.lpszMenuName = NULL;
	//wndclass.style = CS_HREDRAW | CS_VREDRAW;
	//RegisterClass(&wndclass);

	//cs.lpszClass = L"asdasd";

	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, 0, LoadIcon(NULL,IDI_WARNING));
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW);
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



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	static int index = 1;
	SetClassLong(m_hWnd, GCL_HICON, (LONG)m_HICONs[index]);
	index = ++index % 3;
	CFrameWnd::OnTimer(nIDEvent);


	CTime t = CTime::GetCurrentTime();
	CString str = t.Format(L"%H:%M:%S");
	CClientDC dc(this);
	CSize timeSize = dc.GetTextExtent(str);
	m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(IDS_TIME), IDS_TIME, SBPS_NORMAL, timeSize.cx);
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(IDS_TIME), str);

	if (m_progressCtrl)
		m_progressCtrl.StepIt();
}


void CMainFrame::OnNewtool()
{
	// TODO: Add your command handler code here
	//if (m_newToolBar.IsWindowVisible()) {
	//	m_newToolBar.ShowWindow(SW_HIDE);
	//	
	//}
	//else {
	//	m_newToolBar.ShowWindow(SW_SHOW);
	//}

	//RecalcLayout();
	//DockControlBar(&m_newToolBar);

	ShowControlBar(&m_newToolBar,!m_newToolBar.IsWindowVisible(),FALSE);
}


void CMainFrame::OnUpdateNewtool(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_newToolBar.IsWindowVisible());
}

LRESULT CMainFrame::OnProgress(WPARAM wParam, LPARAM lParam)
{
	CRect rect;
	m_wndStatusBar.GetItemRect(m_wndStatusBar.CommandToIndex(IDS_PROGRESS), &rect);
	m_progressCtrl.Create(WS_CHILD | WS_VISIBLE /*| PBS_VERTICAL*/, rect, &m_wndStatusBar, 123123);
	m_progressCtrl.SetPos(50);
	return 0;
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CFrameWnd::OnPaint() for painting messages
	CRect rect;
	m_wndStatusBar.GetItemRect(m_wndStatusBar.CommandToIndex(IDS_PROGRESS), &rect);
	if (m_progressCtrl.m_hWnd)
	{
		m_progressCtrl.MoveWindow(rect);
		m_progressCtrl.SetPos(50);
	}	
}
