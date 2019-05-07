#include "stdafx.h"
#include "Graph.h"

IMPLEMENT_SERIAL(CGraph, CObject, 1)

CGraph::CGraph()
{
}

CGraph::CGraph(UINT nDrawType, CPoint ptOr, CPoint ptEnd)
{
	m_nDrawType = nDrawType;
	m_ptOr = ptOr;
	m_ptEnd = ptEnd;
}

CGraph::~CGraph()
{
}


void CGraph::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_nDrawType << m_ptOr << m_ptEnd;
	}
	else
	{	// loading code
		ar >> m_nDrawType >> m_ptOr >> m_ptEnd;
	}
}

void CGraph::Draw(CDC * pDC)
{
	CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush* pPrvBrush = pDC->SelectObject(pBrush);
	switch (m_nDrawType)
	{
	case 1:
		pDC->SetPixel(m_ptEnd, RGB(0, 0, 0));
		break;
	case 2:
		pDC->MoveTo(m_ptOr);
		pDC->LineTo(m_ptEnd);
		break;
	case 3:
		pDC->Rectangle(CRect(m_ptOr, m_ptEnd));
		break;
	case 4:
		pDC->Ellipse(CRect(m_ptOr, m_ptEnd));
		break;
	default:
		break;
	}

	pDC->SelectObject(pPrvBrush);
}
