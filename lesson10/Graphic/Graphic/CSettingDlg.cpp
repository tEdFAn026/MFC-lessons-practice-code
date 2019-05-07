// DSettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graphic.h"
#include "CSettingDlg.h"
#include "afxdialogex.h"


// DSettingDlg dialog

IMPLEMENT_DYNAMIC(CSettingDlg, CDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SETTING, pParent)
	, m_nLineWidth(0)
	, m_nLineType(0)
{
	m_brush.CreateSolidBrush(RGB(200, 0, 128));
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LINE_WIDTH, m_nLineWidth);
	DDX_CBIndex(pDX, IDC_COMBO_LINETYPE, m_nLineType);
	DDX_Control(pDX, IDOK, m_btnOKTest);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_LINE_WIDTH, &CSettingDlg::OnChangeEditLineWidth)
	ON_CBN_SELCHANGE(IDC_COMBO_LINETYPE, &CSettingDlg::OnSelchangeComboLinetype)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// DSettingDlg message handlers


BOOL CSettingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CComboBox* pLineType = (CComboBox*)GetDlgItem(IDC_COMBO_LINETYPE);
	pLineType->AddString(L"shixian");
	pLineType->AddString(L"suxian");
	pLineType->AddString(L"dianxian");
	pLineType->SetCurSel(m_nLineType);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CSettingDlg::OnChangeEditLineWidth()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	Invalidate();
}


void CSettingDlg::OnSelchangeComboLinetype()
{
	// TODO: Add your control notification handler code here
	Invalidate();
}


void CSettingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialogEx::OnPaint() for painting messages
	UpdateData();

	CPen pen(m_nLineType, m_nLineWidth, m_clr);
	CPen* pPrvPen = dc.SelectObject(&pen);
	CRect rect;

	GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);
	ScreenToClient(rect);

	dc.MoveTo(rect.left + 20, rect.top + rect.Height() / 2);
	dc.LineTo(rect.right - 20, rect.top + rect.Height() / 2);

	dc.SelectObject(pPrvPen);

}


HBRUSH CSettingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_LINESETTING) {
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkMode(TRANSPARENT);
		return m_brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_EDIT_LINE_WIDTH) {
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(200, 0, 128));
		return m_brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_TEXT) {
		pDC->SelectObject(m_pFont);
	}

	if (pWnd->GetDlgCtrlID() == IDOK) {
		//pDC->SetTextColor(RGB(255, 255, 255));
		//pDC->SetBkColor(RGB(200, 0, 128));
		//return m_brush;
	}

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
