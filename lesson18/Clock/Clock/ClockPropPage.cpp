// ClockPropPage.cpp : Implementation of the CClockPropPage property page class.

#include "stdafx.h"
#include "Clock.h"
#include "ClockPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CClockPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CClockPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CClockPropPage, "CLOCK.ClockPropPage.1",
	0xdcd63cfa, 0x3420, 0x4138, 0x99, 0x1b, 0x67, 0x1b, 0xe7, 0xaa, 0x98, 0xee)

// CClockPropPage::CClockPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CClockPropPage

BOOL CClockPropPage::CClockPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CLOCK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CClockPropPage::CClockPropPage - Constructor

CClockPropPage::CClockPropPage() :
	COlePropertyPage(IDD, IDS_CLOCK_PPG_CAPTION)
	, m_updateIntrerval(0)
{
}

// CClockPropPage::DoDataExchange - Moves data between page and properties

void CClockPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
	DDP_Text(pDX, IDC_EDIT1, m_updateIntrerval, _T("Interval"));
	DDX_Text(pDX, IDC_EDIT1, m_updateIntrerval);
}

// CClockPropPage message handlers
