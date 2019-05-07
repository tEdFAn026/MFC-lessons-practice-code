#pragma once

// ClockPropPage.h : Declaration of the CClockPropPage property page class.


// CClockPropPage : See ClockPropPage.cpp for implementation.

class CClockPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CClockPropPage)
	DECLARE_OLECREATE_EX(CClockPropPage)

// Constructor
public:
	CClockPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_CLOCK };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
public:
	short m_updateIntrerval;
};

