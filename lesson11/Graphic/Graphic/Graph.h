#pragma once
class CGraph
{
public:
	CGraph(UINT nDrawType,CPoint ptOr,CPoint ptEnd);
	~CGraph();
	UINT m_nDrawType;
	CPoint m_ptOr;
	CPoint m_ptEnd;
};

