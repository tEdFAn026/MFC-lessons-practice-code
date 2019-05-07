
// ADODlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADO.h"
#include "ADODlg.h"
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


// CADODlg dialog



CADODlg::CADODlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CADODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CADODlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CADODlg::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CADODlg message handlers

BOOL CADODlg::OnInitDialog()
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
	AfxOleInit();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADODlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CADODlg::OnPaint()
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
HCURSOR CADODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include "SQLDATA.h"
void CADODlg::OnBnClickedButtonQuery()
{
	// TODO: Add your control notification handler code here
	CoInitialize(NULL);
	_ConnectionPtr pConn(_uuidof(Connection));
	_RecordsetPtr pRst(_uuidof(Recordset));
	_CommandPtr pCmd(_uuidof(Command));

	char connectionBuf[256];
	//I did update the "SQLDATA.h" because its contains mysql uid and pwd,etc.
	sprintf_s(connectionBuf, "Provider = MSDASQL.1; Persist Security Info = False; Extended Properties = \"Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=%s;UID=%s;PWD=%s;DATABASE=%s;PORT=%s\"", MYSQL_DATA_SERVER, MYSQL_DATA_UID, MYSQL_DATA_PWD, MYSQL_DATA_DATABASE, MYSQL_DATA_PORT);
	//sprintf_s(connectionBuf, "Provider = MSDASQL.1; Persist Security Info = False; Extended Properties = \"Driver=MySQL ODBC 8.0 ANSI Driver;DSN=MysqlA;SERVER=%s;UID=%s;PWD=%s;DATABASE=%s;PORT=%s\"", MYSQL_DATA_SERVER, MYSQL_DATA_UID, MYSQL_DATA_PWD, MYSQL_DATA_DATABASE, MYSQL_DATA_PORT);
	
	pConn->ConnectionString = connectionBuf;
	try
	{
		pConn->Open("", "", "", adConnectUnspecified);
	}
	catch (_com_error &err)
	{
		DWORD dw = GetLastError();
		CStringA str;
		char* pErrMsg = WtoA(err.ErrorMessage());
		CString errDesc = err.Description();
		char* pErrorDesc = WtoA(errDesc);
		str.Format("DB ERROR!\nErrorMsg: %s,\nErrorDesc: %s\nFile: %s,\nLine: %d.\n", pErrMsg, pErrorDesc, __FILE__, __LINE__);
		delete pErrMsg;
		delete pErrorDesc;
		MessageBoxA(m_hWnd, str, "", MB_ICONERROR);
		pConn.Release();

		return;
	}

	//pRst = pConn->Execute("SELECT * FROM BIC_RECORD", NULL, adCmdText);
	//pRst->Open("SELECT * FROM BIC_RECORD", _variant_t((IDispatch*)pConn), adOpenDynamic, adLockOptimistic, adCmdText);
	pCmd->put_ActiveConnection(_variant_t((IDispatch*)pConn));
	pCmd->CommandText = "SELECT * FROM BIC_RECORD";
	pRst = pCmd->Execute(NULL, NULL, adCmdText);
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	pListBox->ResetContent();
	while (!pRst->rsEOF) {
		if (!pListBox)
			break;
		char buf[128];
		sprintf_s(buf, "BIC:%s,Used:%s", (char*)(_bstr_t)pRst->GetCollect("BIC"), (char*)(_bstr_t)pRst->GetCollect("USED"));

		DWORD dBufSize = MultiByteToWideChar(CP_ACP, 0, buf, strlen(buf), NULL, 0);
		wchar_t* pWBuf = new wchar_t[dBufSize + 1];
		memset(pWBuf, 0, dBufSize + 1);
		int nRet = MultiByteToWideChar(CP_ACP, 0, buf, strlen(buf) + 1, pWBuf, dBufSize + 1);

		pListBox->AddString(pWBuf);
		delete pWBuf;
		pRst->MoveNext();
	}
	MessageBox(L"Success");
	pRst->Close();
	pConn->Close();
	pCmd.Release();
	pRst.Release();
	pConn.Release();
	CoUninitialize();
}

char* CADODlg::WtoA(CStringW str) {
	char*     pElementText;
	int    iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset(pElementText, 0, sizeof(char) * (iTextLen + 1));
	WideCharToMultiByte(CP_ACP, 0, str, -1, pElementText, iTextLen, NULL, NULL);
	return pElementText;
}
