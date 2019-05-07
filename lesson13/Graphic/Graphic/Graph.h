#pragma once
class CGraph:public CObject
{
	DECLARE_SERIAL(CGraph);
public:
	CGraph();
	CGraph(UINT nDrawType,CPoint ptOr,CPoint ptEnd);
	~CGraph();
	UINT m_nDrawType;
	CPoint m_ptOr;
	CPoint m_ptEnd;
	virtual void Serialize(CArchive& ar);

	void Draw(CDC* pDC);
};

