#pragma once


// CProp2 dialog

class CProp1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp1)

public:
	CProp1();
	virtual ~CProp1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_LARGE1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	BOOL m_bCheck1;
	BOOL m_bCheck2;
	BOOL m_bCheck3;
	virtual LRESULT OnWizardNext();
};
