// RunBtn.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "RunBtn.h"


// CRunBtn

IMPLEMENT_DYNAMIC(CRunBtn, CButton)

CRunBtn::CRunBtn()
	: m_pOtherRunBtn(NULL)
{

}

CRunBtn::~CRunBtn()
{
}


BEGIN_MESSAGE_MAP(CRunBtn, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CRunBtn message handlers




void CRunBtn::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	ShowWindow(SW_HIDE);
	if (m_pOtherRunBtn && m_pOtherRunBtn != this)
		m_pOtherRunBtn->ShowWindow(SW_SHOW);
	CButton::OnMouseMove(nFlags, point);
}
