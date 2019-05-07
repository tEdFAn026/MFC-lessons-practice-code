
// DllTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DllTest.h"
#include "DllTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDllTestDlg dialog



CDllTestDlg::CDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLLTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDllTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDllTestDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUBTRACT, &CDllTestDlg::OnBnClickedButtonSubtract)
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CDllTestDlg::OnBnClickedButtonOutput)
END_MESSAGE_MAP()


// CDllTestDlg message handlers

BOOL CDllTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDllTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDllTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//extern int add(int a, int b);
//_declspec(dllimport) int add(int a, int b);
//extern int subtract(int a, int b);
//#include "..\..\DLL1\DLL1\DLL1.h"
//#pragma comment(lib, "DLL1.lib")
void CDllTestDlg::OnBnClickedButtonAdd()
{
	// TODO: Add your control notification handler code here
	HINSTANCE hINSTANCE = LoadLibrary(L"DLL2.dll");
	typedef int (_stdcall *ADDPROC)(int a, int b);
	ADDPROC add_dll2 = (ADDPROC)GetProcAddress(hINSTANCE, "add");
	if (!add_dll2) return;

	CString str;
	str.Format(L"5+3=%d", add_dll2(5, 3));
	MessageBox(str);
	FreeLibrary(hINSTANCE);
}


void CDllTestDlg::OnBnClickedButtonSubtract()
{
	// TODO: Add your control notification handler code here
	HINSTANCE hINSTANCE = LoadLibrary(L"DLL2.dll");
	typedef int (*ADDPROC)(int a, int b);
	ADDPROC subtract_dll2 = (ADDPROC)GetProcAddress(hINSTANCE, MAKEINTRESOURCEA(2));
	if (!subtract_dll2) return;

	CString str;
	str.Format(L"5-3=%d", subtract_dll2(5, 3));
	MessageBox(str);
	FreeLibrary(hINSTANCE);
}


void CDllTestDlg::OnBnClickedButtonOutput()
{
	// TODO: Add your control notification handler code here
	//Point pt;
	//pt.output(5, 3);
}
