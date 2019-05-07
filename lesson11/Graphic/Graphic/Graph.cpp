#include "stdafx.h"
#include "Graph.h"


CGraph::CGraph(UINT nDrawType, CPoint ptOr, CPoint ptEnd)
{
	m_nDrawType = nDrawType;
	m_ptOr = ptOr;
	m_ptEnd = ptEnd;
}

CGraph::~CGraph()
{
}
