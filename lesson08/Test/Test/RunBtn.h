#pragma once


// CRunBtn

class CRunBtn : public CButton
{
	DECLARE_DYNAMIC(CRunBtn)

public:
	CRunBtn();
	virtual ~CRunBtn();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CRunBtn* m_pOtherRunBtn;
};


