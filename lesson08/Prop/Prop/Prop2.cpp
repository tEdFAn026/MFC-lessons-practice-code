// Prop2.cpp : implementation file
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop2.h"
#include "PropSheet.h"
#include "afxdialogex.h"


// CProp2 dialog

IMPLEMENT_DYNAMIC(CProp2, CPropertyPage)

CProp2::CProp2()
	: CPropertyPage(IDD_PROPPAGE_LARGE2)
	, m_strMoney(_T(""))
{

}

CProp2::~CProp2()
{
}

void CProp2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO3, m_strMoney);
}


BEGIN_MESSAGE_MAP(CProp2, CPropertyPage)
END_MESSAGE_MAP()


// CProp2 message handlers


BOOL CProp2::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class
	CPropSheet* pPropSheet = (CPropSheet*)GetParent();
	if (pPropSheet)
		pPropSheet->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH | PSWIZB_CANCEL);

	return CPropertyPage::OnSetActive();
}


BOOL CProp2::OnInitDialog()
{ 
	CPropertyPage::OnInitDialog();

	// TODO:  Add extra initialization here
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO3);
	pComboBox->AddString(L"<1000");
	pComboBox->AddString(L"1000-2000");
	pComboBox->AddString(L">2000");
	pComboBox->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CProp2::OnWizardFinish()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData();

	return CPropertyPage::OnWizardFinish();
}
