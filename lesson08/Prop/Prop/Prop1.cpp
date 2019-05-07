// Prop2.cpp : implementation file
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop1.h"
#include "PropSheet.h"
#include "afxdialogex.h"


// CProp2 dialog

IMPLEMENT_DYNAMIC(CProp1, CPropertyPage)

CProp1::CProp1()
	: CPropertyPage(IDD_PROPPAGE_LARGE1)
	, m_bCheck1(FALSE)
	, m_bCheck2(FALSE)
	, m_bCheck3(FALSE)
{

}

CProp1::~CProp1()
{
}

void CProp1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_bCheck1);
	DDX_Check(pDX, IDC_CHECK2, m_bCheck2);
	DDX_Check(pDX, IDC_CHECK3, m_bCheck3);
}


BEGIN_MESSAGE_MAP(CProp1, CPropertyPage)
END_MESSAGE_MAP()


// CProp2 message handlers


BOOL CProp1::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class
	CPropSheet* pPropSheet = (CPropSheet*)GetParent();
	if (pPropSheet)
		pPropSheet->SetWizardButtons(PSWIZB_BACK |PSWIZB_NEXT | PSWIZB_CANCEL);

	return CPropertyPage::OnSetActive();
}


LRESULT CProp1::OnWizardNext()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData();
	if (m_bCheck1 || m_bCheck2 || m_bCheck3)
		return CPropertyPage::OnWizardNext();
	else {
		MessageBox(L"Plz choise");
		return -1;
	}
}
