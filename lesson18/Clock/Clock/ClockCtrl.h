#pragma once

// ClockCtrl.h : Declaration of the CClockCtrl ActiveX Control class.


// CClockCtrl : See ClockCtrl.cpp for implementation.

class CClockCtrl : public COleControl
{
	DECLARE_DYNCREATE(CClockCtrl)

// Constructor
public:
	CClockCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CClockCtrl();

	DECLARE_OLECREATE_EX(CClockCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CClockCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CClockCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CClockCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		eventidNewMinute = 1L,
		dispidHello = 2L,
		dispidInterval = 1
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	void OnIntervalChanged();
	SHORT m_Interval;
	void Hello();

	void NewMinute()
	{
		FireEvent(eventidNewMinute, EVENT_PARAM(VTS_NONE));
	}
};

