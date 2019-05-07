
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
	m_socket = 0;
}

CChatDlg::~CChatDlg()
{
	if (m_socket)
		closesocket(m_socket);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(UM_SOCK,&CChatDlg::OnSock)
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

LRESULT CChatDlg::OnSock(WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(lParam))
	{
	case FD_READ: {
		WSABUF wsabuf;
		wsabuf.buf = new char[256];
		wsabuf.len = 256;
		DWORD dwRead;
		DWORD dwFlag = 0;
		SOCKADDR_IN addrFrom;
		int len = sizeof(SOCKADDR);
		if (SOCKET_ERROR == WSARecvFrom(m_socket, &wsabuf, 1, &dwRead, &dwFlag, (SOCKADDR*)&addrFrom, &len, NULL, NULL)) {
			MessageBox(L"Recv data fail!");
			return 1;
		}
		CString str;
		//wchar_t fromBuf[32];
		//InetNtopW(AF_INET, &addrFrom.sin_addr, (PWSTR)&fromIPBuf, 32);
		HOSTENT *pHost;
		pHost = gethostbyaddr((char*)&addrFrom.sin_addr.S_un.S_addr, 4, AF_INET);
		DWORD dwAddrSize = strlen(pHost->h_name) + 1;
		DWORD dBufSize = MultiByteToWideChar(CP_ACP, 0, pHost->h_name, dwAddrSize, NULL, 0);
		wchar_t* fromBuf = new wchar_t[dBufSize];
		memset(fromBuf, 0, dBufSize);
		int nRet = MultiByteToWideChar(CP_ACP, 0, pHost->h_name, dwAddrSize, fromBuf, dBufSize);
		str.Format(L"%s say:%s", fromBuf, (wchar_t*)wsabuf.buf);
		delete fromBuf;

		CString strtemp;
		GetDlgItemText(IDC_EDIT_RECV, strtemp);
		if (!strtemp.IsEmpty())
			strtemp += "\r\n";
		strtemp += str;
		SetDlgItemText(IDC_EDIT_RECV, strtemp);
		//swprintf_s(tempBuf, L"%s say:%s", fromIPBuf, (wchar_t*)recvBuf);
		break; }
	default:
		break;
	}
	return 0;
}



BOOL CChatDlg::InitSocket()
{
	m_socket = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, 0);
	if (INVALID_SOCKET == m_socket) {
		MessageBox(L"Create Scoket fail");
		return FALSE;
	}

	SOCKADDR_IN addrSock;
	addrSock.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(6000);

	if (SOCKET_ERROR == bind(m_socket, (SOCKADDR*)&addrSock, sizeof(SOCKADDR))) {
		MessageBox(L"Bind Scoket fail");
		return FALSE;
	}

	if (SOCKET_ERROR == WSAAsyncSelect(m_socket, m_hWnd, UM_SOCK, FD_READ)) {
		MessageBox(L"Read Event Scoket fail");
		return FALSE;
	}

	return TRUE;
}


void CChatDlg::OnBnClickedButtonSend()
{
	// TODO: Add your control notification handler code here
	CIPAddressCtrl* pIP = (CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1);
	DWORD dwIP;
	pIP->GetAddress(dwIP)
		;
	SOCKADDR_IN addrTo;
	CString strHostName;
	HOSTENT* pHost;
	if (GetDlgItemText(IDC_EDIT_HOSTNAME, strHostName), strHostName.IsEmpty())
		addrTo.sin_addr.S_un.S_addr = htonl(dwIP);
	else { 
		int len = WideCharToMultiByte(CP_ACP, 0, strHostName, strHostName.GetLength(), NULL, 0, NULL, NULL);
		char * pHostName = new char[len + 1];  
		memset(pHostName, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, strHostName, strHostName.GetLength(), pHostName, len, NULL, NULL);
		//char chHostName[128];
		//gethostname(chHostName, 128);
		pHost = gethostbyname(pHostName);
		delete pHostName;
		addrTo.sin_addr.S_un.S_addr = *((DWORD*)pHost->h_addr_list[0]);
	}

	addrTo.sin_family = AF_INET;
	addrTo.sin_port = htons(6000);

	CString strSend;
	GetDlgItemText(IDC_EDIT_SEND, strSend);
	wchar_t * pSend = strSend.AllocSysString();

	WSABUF wsabuf;
	DWORD dwSend;
	int len = (strSend.GetLength() + 1) * sizeof(TCHAR);
	wsabuf.buf = (char*) strSend.GetBuffer();
	wsabuf.len = len;
	if (SOCKET_ERROR == WSASendTo(m_socket, &wsabuf, 1, &dwSend, 0, (SOCKADDR*)&addrTo, sizeof(SOCKADDR), NULL, NULL)) {
		MessageBox(L"Send data fail!");
	}
	
	SetDlgItemText(IDC_EDIT_SEND, L"");
}
