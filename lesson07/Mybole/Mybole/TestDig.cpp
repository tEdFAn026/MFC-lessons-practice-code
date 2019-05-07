// TestDig.cpp : implementation file
//

#include "stdafx.h"
#include "Mybole.h"
#include "TestDig.h"
#include "afxdialogex.h"


// CTestDig dialog

IMPLEMENT_DYNAMIC(CTestDig, CDialogEx)

CTestDig::CTestDig(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_iNum1(0)
	, m_iNum2(0)
	, m_iNum3(0)
{

}

CTestDig::~CTestDig()
{
}

void CTestDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_iNum1);
	DDV_MinMaxInt(pDX, m_iNum1, 0, 100);
	DDX_Text(pDX, IDC_EDIT2, m_iNum2);
	DDV_MinMaxInt(pDX, m_iNum2, 0, 100);
	DDX_Text(pDX, IDC_EDIT3, m_iNum3);
	DDV_MinMaxInt(pDX, m_iNum2, 0, 100);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CTestDig, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CTestDig::OnClickedButtonAdd)
	ON_STN_CLICKED(IDC_STATIC_NUMBER1, &CTestDig::OnClickedStaticNumber1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestDig::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CTestDig::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestDig message handlers

void CTestDig::OnClickedButtonAdd()
{
	// TODO: Add your control notification handler code here
	if (!m_btnAdd)
		m_btnAdd.Create(L"asd", BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123);
	else
		m_btnAdd.DestroyWindow();

	int iR;
	wchar_t  ch1[16], ch2[16], ch3[16];
	
	//GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 16);
	//GetDlgItemText(IDC_EDIT1, ch1, 16);
	
	//GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 16);
	//GetDlgItemText(IDC_EDIT2, ch2, 16);

	//iR = _wtoi(ch1) + _wtoi(ch2);
	//iR = GetDlgItemInt(IDC_EDIT1) + GetDlgItemInt(IDC_EDIT2);
	//_itow_s(iR, ch3, 10);
	//swprintf_s(ch3, L"%d", iR);

	//GetDlgItem(IDC_EDIT3)->SetWindowText(ch3);
	//SetDlgItemText(IDC_EDIT3, ch3);
	//SetDlgItemInt(IDC_EDIT3, iR);
	
	UpdateData();
	m_iNum3 = m_iNum1 + m_iNum2;
	UpdateData(FALSE);

	//m_edit1.GetWindowText(ch1, 10);
	//m_edit2.GetWindowText(ch2, 10);
	//iR = _wtoi(ch1) + _wtoi(ch2);
	//_itow_s(iR, ch3, 10);
	//m_edit3.SetWindowText(ch3);

	//::SendMessage(m_edit1.m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	//GetDlgItem(IDC_EDIT2)->SendMessage(WM_GETTEXT, 10, (LPARAM)ch2);
	//iR = _wtoi(ch1) + _wtoi(ch2);
	//_itow_s(iR, ch3, 10);
	//m_edit3.SendMessage(WM_SETTEXT, 0, (LPARAM)ch3);

	//SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 10, (LPARAM)ch1);
	//SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 10, (LPARAM)ch2);
	//iR = _wtoi(ch1) + _wtoi(ch2);
	//_itow_s(iR, ch3, 10);
	//SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3);
	//SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 0, -1);
	//m_edit3.SetFocus();
}


void CTestDig::OnClickedStaticNumber1()
{
	// TODO: Add your control notification handler code here
	CString str;
	if (GetDlgItem(IDC_STATIC_NUMBER1)-> GetWindowText(str), str == "Number1:") {
		GetDlgItem(IDC_STATIC_NUMBER1)->SetWindowText(L"ShuZi1:");
	}
	else {
		GetDlgItem(IDC_STATIC_NUMBER1)->SetWindowText(L"Number1:");
	}

	m_edit3.SetFocus();
}


void CTestDig::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	static CRect rectLarge;
	static CRect rectSmall;

	if (rectLarge.IsRectNull()) {
		CRect rectSEPARATOR;
		GetWindowRect(&rectLarge);
		GetDlgItem(IDC_SEPARATOR)->GetWindowRect(&rectSEPARATOR);

		rectSmall = rectLarge;
		rectSmall.bottom = rectSEPARATOR.bottom;
	}

	CString str;
	if (GetDlgItemText(IDC_BUTTON2, str), str == "Skim<<") {
		SetDlgItemText(IDC_BUTTON2, L"Extend>>");

		SetWindowPos(NULL, 0, 0, rectSmall.Width(), rectSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	else {
		SetDlgItemText(IDC_BUTTON2, L"Skim<<");

		SetWindowPos(NULL, 0, 0, rectLarge.Width(), rectLarge.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}


}


void CTestDig::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	GetNextDlgTabItem(GetFocus())->SetFocus();

	//CDialogEx::OnOK();
}

WNDPROC prevProc;
LRESULT CALLBACK WinSunProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_CHAR && wParam == 0x0d) {
		//::SetFocus(::GetNextWindow(hWnd, GW_HWNDNEXT));

		//SetFocus(::GetWindow(hWnd, GW_HWNDNEXT));
		//HWND hNextWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
		//SetFocus(::GetWindow(hNextWnd, GW_HWNDNEXT));

		SetFocus(::GetNextDlgTabItem(::GetParent(hWnd), hWnd, false));
		return 1;
	}
	else
		return prevProc(hWnd, uMsg, wParam, lParam);
}

BOOL CTestDig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_edit1.SetFocus();
	prevProc = (WNDPROC)SetWindowLong(GetDlgItem(IDC_EDIT1)->m_hWnd, GWL_WNDPROC, (LONG)WinSunProc);

	return FALSE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
