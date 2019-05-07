#pragma once
#include "Prop0.h"
#include "Prop1.h"
#include "Prop2.h"

// CPropSheet

class CPropSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropSheet)

public:
	CPropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CPropSheet();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CProp0 m_Prop0;
	CProp1 m_Prop1;
	CProp2 m_Prop2;
};


