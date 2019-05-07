#pragma once


// CProp1 dialog

class CProp0 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp0)

public:
	CProp0();
	virtual ~CProp0();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_LARGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	int m_iOccupation;
	virtual LRESULT OnWizardNext();
	virtual BOOL OnInitDialog();
	CString m_strWorkAddr;
};
