
// ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"
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


// CChatDlg dialog



CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHAT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_RECVDATA,&CChatDlg::OnRecvData)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CChatDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()


// CChatDlg message handlers

BOOL CChatDlg::OnInitDialog()
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
	InitSocket();
	SRecvParam* pRecvParam = new SRecvParam();
	pRecvParam->sock = m_Socket;
	pRecvParam->hWnd = m_hWnd;
	HANDLE hThread = CreateThread(NULL, 0, RecvProc, (LPVOID)pRecvParam, 0,NULL);
	CloseHandle(hThread);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatDlg::OnPaint()
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
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CChatDlg::OnRecvData(WPARAM wParam, LPARAM lParam)
{
	CString str = (wchar_t*)lParam;
	CString strtemp;
	GetDlgItemText(IDC_EDIT_RECV, strtemp);
	if (!strtemp.IsEmpty())
		strtemp += "\r\n";
	strtemp += str;
	SetDlgItemText(IDC_EDIT_RECV, strtemp);
	return 0;
}

BOOL CChatDlg::InitSocket()
{
	m_Socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == m_Socket) {
		MessageBox(L"Socket create fail!");
		return FALSE;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	
	int retval;
	retval = bind(m_Socket, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	if (SOCKET_ERROR == retval) {
		closesocket(m_Socket);
		MessageBox(L"Socket bind fail!");
		return FALSE;
	}

	return TRUE;
}

DWORD CChatDlg::RecvProc(LPVOID lpParameter)
{
	SOCKET sock = ((SRecvParam*)lpParameter)->sock;
	HWND hWnd = ((SRecvParam*)lpParameter)->hWnd;

	SOCKADDR_IN addrRecv;
	int len = sizeof(SOCKADDR);

	char recvBuf[128];
	wchar_t tempBuf[256];
	int retval;
	while (true)
	{
		retval = recvfrom(sock, recvBuf, 128, 0, (SOCKADDR*)&addrRecv, &len);
		if(SOCKET_ERROR == retval)
			break;

		wchar_t fromIPBuf[32];
		InetNtopW(AF_INET, &addrRecv.sin_addr, (PWSTR)&fromIPBuf, 32);
		swprintf_s(tempBuf, L"%s say:%s", fromIPBuf, (wchar_t*)recvBuf);
		::PostMessage(hWnd, WM_RECVDATA, 0, (LPARAM)tempBuf);
	}
	return 0;
}


void CChatDlg::OnBnClickedButtonSend()
{
	// TODO: Add your control notification handler code here
	CIPAddressCtrl* pIP = (CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1);
	DWORD dwIP;
	pIP->GetAddress(dwIP);

	SOCKADDR_IN addrTo;
	addrTo.sin_addr.S_un.S_addr = htonl(dwIP);
	addrTo.sin_family = AF_INET;
	addrTo.sin_port = htons(6000);

	CString strSend;
	GetDlgItemText(IDC_EDIT_SEND, strSend);
	wchar_t * pSend = strSend.AllocSysString();
	sendto(m_Socket, (char *)pSend, (wcslen(pSend) + 1) * sizeof(TCHAR), 0, (SOCKADDR*)&addrTo, sizeof(SOCKADDR));
	SetDlgItemText(IDC_EDIT_SEND, L"");
}
