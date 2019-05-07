
// GraphicDoc.cpp : implementation of the CGraphicDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Graphic.h"
#endif

#include "GraphicDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGraphicDoc

IMPLEMENT_DYNCREATE(CGraphicDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraphicDoc, CDocument)
END_MESSAGE_MAP()


// CGraphicDoc construction/destruction

CGraphicDoc::CGraphicDoc()
{
	// TODO: add one-time construction code here

}

CGraphicDoc::~CGraphicDoc()
{
}

BOOL CGraphicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	//SetTitle(L"Ted");

	return TRUE;
}




// CGraphicDoc serialization
#define GRAPH
#ifdef GRAPH
#include "GraphicView.h"
#include "Graph.h"
#endif
void CGraphicDoc::Serialize(CArchive& ar)
{
#ifdef GRAPH
	POSITION pos = GetFirstViewPosition();
/*	CGraphicView* pView = (CGraphicView*)GetNextView(pos);
	pView->*/m_obArray.Serialize(ar);
#endif 
	if (ar.IsStoring())
	{
		// TODO: add storing code here
#ifdef GRAPH
		//int size = pView->m_obArray.GetSize();
		//ar << size;
		//for (int i = 0; i < size; i++) {
		//	ar << pView->m_obArray.GetAt(i);
		//}
#else
		int i = 5;
		char ch = 'b';
		float f = 1.2f;
		CString str(L"Hello");
		ar << i << ch << f << str;
#endif 
	}
	else
	{
		// TODO: add loading code here
#ifdef GRAPH
		//int size;
		//ar >> size;
		//CGraph *pGraph;
		//for (int i = 0; i < size; i++) {
		//	ar >> pGraph;
		//	pView->m_obArray.Add(pGraph);
		//}
#else
		int i;
		char ch;
		float f;
		CString str;
		ar >> i >> ch >> f >> str;

		CString strRes;
		strRes.Format(L"%d,%c,%f,%s", i, ch, f, str);
		AfxMessageBox(strRes);
#endif 
	}
}
#undef  GRAPH

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CGraphicDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CGraphicDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CGraphicDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CGraphicDoc diagnostics

#ifdef _DEBUG
void CGraphicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraphicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGraphicDoc commands


void CGraphicDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
	int nCount = m_obArray.GetSize();
	for (int i = 0; i < nCount; i++) {
		delete m_obArray.GetAt(i);
	}
	m_obArray.RemoveAll();
	CDocument::DeleteContents();
}
