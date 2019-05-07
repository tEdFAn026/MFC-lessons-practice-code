// Prop1.cpp : implementation file
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop0.h"
#include "PropSheet.h"
#include "afxdialogex.h"


// CProp1 dialog

IMPLEMENT_DYNAMIC(CProp0, CPropertyPage)

CProp0::CProp0()
	: CPropertyPage(IDD_PROPPAGE_LARGE)
	, m_iOccupation(-1)
	, m_strWorkAddr(_T(""))
{

}

CProp0::~CProp0()
{
}

void CProp0::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_iOccupation);
	DDX_LBString(pDX, IDC_LIST1, m_strWorkAddr);
}


BEGIN_MESSAGE_MAP(CProp0, CPropertyPage)
END_MESSAGE_MAP()


// CProp1 message handlers


BOOL CProp0::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class
	CPropSheet* pPropSheet = (CPropSheet*)GetParent();
	if (pPropSheet)
		pPropSheet->SetWizardButtons(PSWIZB_NEXT | PSWIZB_CANCEL);

	return CPropertyPage::OnSetActive();
}


LRESULT CProp0::OnWizardNext()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData();
	if (m_iOccupation == -1 || m_strWorkAddr.IsEmpty()) {
		MessageBox(L"plz chiose!");
		return -1;
	}

	return CPropertyPage::OnWizardNext();
}


BOOL CProp0::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  Add extra initialization here
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	pListBox->AddString(L"bj");
	pListBox->AddString(L"tj");
	pListBox->AddString(L"sh");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
