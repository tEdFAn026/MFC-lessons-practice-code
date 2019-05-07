// ClockCtrl.cpp : Implementation of the CClockCtrl ActiveX Control class.

#include "stdafx.h"
#include "Clock.h"
#include "ClockCtrl.h"
#include "ClockPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CClockCtrl, COleControl)

// Message map

BEGIN_MESSAGE_MAP(CClockCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Dispatch map

BEGIN_DISPATCH_MAP(CClockCtrl, COleControl)
	DISP_FUNCTION_ID(CClockCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
	DISP_PROPERTY_NOTIFY_ID(CClockCtrl, "Interval", dispidInterval, m_Interval, OnIntervalChanged, VT_I2)
	DISP_FUNCTION_ID(CClockCtrl, "Hello", dispidHello, Hello, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CClockCtrl, COleControl)
	EVENT_STOCK_CLICK()
	EVENT_CUSTOM_ID("NewMinute", eventidNewMinute, NewMinute, VTS_NONE)
END_EVENT_MAP()

// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CClockCtrl, 2)
	PROPPAGEID(CClockPropPage::guid)
	PROPPAGEID(CLSID_CColorPropPage)
END_PROPPAGEIDS(CClockCtrl)

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CClockCtrl, "CLOCK.ClockCtrl.1",
	0xed3db106, 0xf475, 0x49e8, 0xb0, 0x1d, 0xd, 0xc5, 0x4, 0x70, 0xad, 0x45)

// Type library ID and version

IMPLEMENT_OLETYPELIB(CClockCtrl, _tlid, _wVerMajor, _wVerMinor)

// Interface IDs

const IID IID_DClock = { 0xF78DF301, 0x71B, 0x4531, { 0xA5, 0xF3, 0xDC, 0x42, 0xDF, 0xDF, 0xE8, 0x98 } };
const IID IID_DClockEvents = { 0x600C57C4, 0xE86C, 0x4D40, { 0x93, 0x44, 0x76, 0x6C, 0x85, 0x28, 0x17, 0xDC } };

// Control type information

static const DWORD _dwClockOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CClockCtrl, IDS_CLOCK, _dwClockOleMisc)

// CClockCtrl::CClockCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CClockCtrl

BOOL CClockCtrl::CClockCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CLOCK,
			IDB_CLOCK,
			afxRegApartmentThreading,
			_dwClockOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CClockCtrl::CClockCtrl - Constructor

CClockCtrl::CClockCtrl()
{
	InitializeIIDs(&IID_DClock, &IID_DClockEvents);
	// TODO: Initialize your control's instance data here.
}

// CClockCtrl::~CClockCtrl - Destructor

CClockCtrl::~CClockCtrl()
{
	// TODO: Cleanup your control's instance data here.
}

// CClockCtrl::OnDraw - Drawing function

void CClockCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
	CBrush brush(TranslateColor(GetBackColor()));
	pdc->FillRect(rcBounds, &brush);
	pdc->SetBkMode(TRANSPARENT);
	pdc->SetTextColor(TranslateColor(GetForeColor()));
	CTime time = CTime::GetCurrentTime();
	if (0 == time.GetSecond()) {
		NewMinute();
	}
	CString str = time.Format("%H:%M:%S");
	CSize size = pdc->GetTextExtent(str);
	pdc->TextOut((rcBounds.Width() - size.cx) / 2, (rcBounds.Height() - size.cy) / 2, str);
}

// CClockCtrl::DoPropExchange - Persistence support

void CClockCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
	PX_Short(pPX, _T("Interval"), m_Interval, 1000);
}


// CClockCtrl::OnResetState - Reset control to default state

void CClockCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


// CClockCtrl::AboutBox - Display an "About" box to the user

void CClockCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CLOCK);
	dlgAbout.DoModal();
}


// CClockCtrl message handlers


int CClockCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(1,m_Interval,NULL);
	return 0;
}


void CClockCtrl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	//Invalidate();
	if (AmbientUserMode())
		InvalidateControl();
	COleControl::OnTimer(nIDEvent);
}


void CClockCtrl::OnIntervalChanged()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here
	if (m_Interval < 0 || m_Interval>6000)
		m_Interval = 1000;
	else {
		m_Interval = m_Interval / 1000 * 1000;
		KillTimer(1);
		SetTimer(1, m_Interval, NULL);
	}
	BoundPropertyChanged(0x1);

	SetModifiedFlag();
}


void CClockCtrl::Hello()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here
	MessageBox(L"HELLO!");
}
