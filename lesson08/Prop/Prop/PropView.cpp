
// PropView.cpp : implementation of the CPropView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Prop.h"
#endif

#include "PropDoc.h"
#include "PropView.h"
#include "PropSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPropView

IMPLEMENT_DYNCREATE(CPropView, CView)

BEGIN_MESSAGE_MAP(CPropView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PROPSHEET, &CPropView::OnPropsheet)
END_MESSAGE_MAP()

// CPropView construction/destruction

CPropView::CPropView():m_iOccupation(-1), m_strWorkAddr(_T("")), m_strMoney(_T(""))
{
	// TODO: add construction code here
	memset(m_bCheck, 0, sizeof(m_bCheck));
}

CPropView::~CPropView()
{
}

BOOL CPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPropView drawing

void CPropView::OnDraw(CDC* pDC)
{
	CPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CFont font;
	font.CreatePointFont(300, L"monofur");

	CFont* pPrvFont = pDC->SelectObject(&font);

	CString strTemp = L"job:";
	switch (m_iOccupation)
	{
	case 0:
		strTemp += L"cxy";
		break;
	case 1:
		strTemp += L"jl";
		break;
	case 2:
		strTemp += L"lb";
		break;
	default:
		break;
	}
	pDC->TextOut(0, 0, strTemp);

	strTemp = L"Addr:" + m_strWorkAddr;
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	pDC->TextOut(0, tm.tmHeight, strTemp);

	strTemp = L"Like:";
	for (int i=0;i<sizeof(m_bCheck)/sizeof(m_bCheck[0]);i++)
	{
		CString str;
		str.Format(L"%d ", i + 1);
		if (m_bCheck[i]) strTemp += L"Check"+ str;
	}
	pDC->TextOut(0, tm.tmHeight * 2, strTemp);

	strTemp = L"Money:" + m_strMoney;
	pDC->TextOut(0, tm.tmHeight * 3, strTemp);
	
	pDC->SelectObject(pPrvFont);
}


// CPropView printing

BOOL CPropView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPropView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPropView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CPropView diagnostics

#ifdef _DEBUG
void CPropView::AssertValid() const
{
	CView::AssertValid();
}

void CPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropDoc* CPropView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropDoc)));
	return (CPropDoc*)m_pDocument;
}
#endif //_DEBUG


// CPropView message handlers


void CPropView::OnPropsheet()
{
	// TODO: Add your command handler code here
	CPropSheet propSheet(L"ShuXing");
	propSheet.SetWizardMode();
	if (ID_WIZFINISH == propSheet.DoModal()) {
		m_iOccupation = propSheet.m_Prop0.m_iOccupation;
		m_strWorkAddr = propSheet.m_Prop0.m_strWorkAddr;

		m_bCheck[0] = propSheet.m_Prop1.m_bCheck1;
		m_bCheck[1] = propSheet.m_Prop1.m_bCheck2;
		m_bCheck[2] = propSheet.m_Prop1.m_bCheck3;

		m_strMoney = propSheet.m_Prop2.m_strMoney;
		Invalidate();
	}
}
