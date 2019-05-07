
// FileView.cpp : implementation of the CFileView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "File.h"
#endif

#include "FileDoc.h"
#include "FileView.h"
#include <fstream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileView

IMPLEMENT_DYNCREATE(CFileView, CView)

BEGIN_MESSAGE_MAP(CFileView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_WENJIAN_DUQU, &CFileView::OnWenjianDuqu)
	ON_COMMAND(ID_WENJIAN_XIERU, &CFileView::OnWenjianXieru)
	ON_COMMAND(ID_FILE_OPEN, &CFileView::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CFileView::OnFileSaveAs)
	ON_COMMAND(ID_REG_READ, &CFileView::OnRegRead)
	ON_COMMAND(ID_REG_WRITE, &CFileView::OnRegWrite)
END_MESSAGE_MAP()

// CFileView construction/destruction

CFileView::CFileView()
{
	// TODO: add construction code here

}

CFileView::~CFileView()
{
}

BOOL CFileView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFileView drawing

void CFileView::OnDraw(CDC* /*pDC*/)
{
	CFileDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFileView printing

BOOL CFileView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFileView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFileView diagnostics

#ifdef _DEBUG
void CFileView::AssertValid() const
{
	CView::AssertValid();
}

void CFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileDoc* CFileView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileDoc)));
	return (CFileDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileView message handlers

//#define FP
//#define FS
//#define WIN32_FILE
#define MFC_FILE
void CFileView::OnWenjianDuqu()
{
	// TODO: Add your command handler code here
#ifdef FP
	FILE *fp;
	if ((fp = _fsopen("1.txt", "rt", _SH_DENYNO)) != NULL)
	{
		char* pBuf;
		fseek(fp, 0, SEEK_END);
		int len = ftell(fp);
		pBuf = new char[len + 1];
		memset(pBuf, 0, len);
		rewind(fp);
		fread(pBuf, 1, len, fp);
		fclose(fp);
		MessageBoxA(m_hWnd, pBuf, "read", 0);
	}
#elif defined(FS)
	ifstream ifs("4.txt");
	char ch[128];
	memset(ch, 0, 128);
	ifs.read(ch, 100);
	ifs.close();
	MessageBoxA(m_hWnd, ch, "read", 0);
#elif defined(WIN32_FILE)
	HANDLE hFlie;
	hFlie = CreateFile(L"5.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	char ch[128];
	DWORD dwReads;
	ReadFile(hFlie, ch, 128, &dwReads, NULL);
	ch[dwReads] = 0;
	CloseHandle(hFlie);
	MessageBoxA(m_hWnd, ch, "read", 0);
#elif defined(MFC_FILE)
	//CFile file(L"6.txt", CFile::modeRead);
	CFile file;
	if (file.Open(L"6.txt", CFile::modeRead)) {
		char* pBuf;
		DWORD dwReads = file.GetLength();
		pBuf = new char[dwReads + 1];
		pBuf[dwReads] = 0;
		file.Read(pBuf, dwReads);
		file.Close();
		MessageBoxA(m_hWnd, pBuf, "read", 0);
	}
	else MessageBox(L"fail");
#endif
}

void CFileView::OnWenjianXieru()
{
	// TODO: Add your command handler code here
#ifdef FP
	FILE *fp;

	if ((fp = _fsopen("1.txt", "wt", _SH_DENYNO)) != NULL)
	{
		fwrite("a\nb", 1, strlen("a\nb"), fp);
		fseek(fp, 0, SEEK_SET);
		fwrite("c", 1, strlen("c"), fp);
		//fclose(fp);
	#ifdef _DEBUG
		char buf[32];
		sprintf_s(buf, "fflush:%d\n", fflush(fp));
		OutputDebugStringA(buf);
	#else
		fflush(fp);
	#endif //_DEBUG
	}
#elif defined(FS)
	ofstream ofs("4.txt");
	ofs.write("a\nb", strlen("a\nb"));
	ofs.close();
#elif defined(WIN32_FILE)
	HANDLE hFlie;
	hFlie = CreateFile(L"5.txt", GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD dwWrites;
	WriteFile(hFlie, "Hello", strlen("Hello"), &dwWrites, NULL);
	CloseHandle(hFlie);
#elif defined(MFC_FILE)
	CFile file(L"6.txt",CFile::modeCreate | CFile::modeWrite);
	file.Write("hahaha", strlen("hahaha"));
	file.Close();
#endif
}

#undef FS

//#define UNICONE_TEXT
void CFileView::OnFileOpen()
{
	// TODO: Add your command handler code here
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle = L"My File Open";
	fileDlg.m_ofn.lpstrFilter = L"Text Flie(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if (IDOK == fileDlg.DoModal()) {
		CFile file(fileDlg.GetFileName(), CFile::modeRead);

		unsigned char s2;
		file.Read(&s2, sizeof(s2));
		int p = s2 << 8;
		file.Read(&s2, sizeof(s2));
		p += s2;

		file.SeekToBegin();
		CString code;
		DWORD dwReads = file.GetLength();
		wchar_t* pWBuf = NULL;
		switch (p)
		{
		case 0xfffe:  //65534
			code = L"Unicode";
			pWBuf = new wchar_t[dwReads / 2 + 1];
			pWBuf[dwReads / 2] = 0;
			file.Read(pWBuf, dwReads);		
			break;
		case 0xfeff://65279
			code = L"Unicode big endian";
			break;
		case 0xefbb://61371
			code = L"UTF-8";
			break;
		default:
			code = L"ANSI";
			char* pBuf = new char[dwReads + 1];
			pBuf[dwReads] = 0;
			file.Read(pBuf, dwReads);
			DWORD dBufSize = MultiByteToWideChar(CP_ACP, 0, pBuf, dwReads + 1, NULL, 0);
			pWBuf = new wchar_t[dBufSize];
			memset(pWBuf, 0, dBufSize);
			int nRet = MultiByteToWideChar(CP_ACP, 0, pBuf, dwReads + 1, pWBuf, dBufSize);
			break;
		}
		//file.Flush();
		file.Close();
		MessageBoxW(pWBuf, L"read", 0);
		MessageBox(code);
		delete pWBuf;
	}
}


const int UNICODE_TXT_FLG = 0xFEFF;

void CFileView::OnFileSaveAs()
{
	// TODO: Add your command handler code here
	CFileDialog fileDlg(FALSE);
	fileDlg.m_ofn.lpstrTitle = L"My File Save As";
	fileDlg.m_ofn.lpstrFilter = L"Text Flie(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	fileDlg.m_ofn.lpstrDefExt = L"txt";
	if (IDOK == fileDlg.DoModal()) {
		CFile file(fileDlg.GetFileName(), CFile::modeCreate | CFile::modeWrite);
		OutputDebugStringW(fileDlg.GetPathName());
		//wchar_t *str = L"Hello!";
		//file.Write(str, wcslen(str)* sizeof(TCHAR));
		file.Write(&UNICODE_TXT_FLG, 2);
		file.Write(fileDlg.GetPathName(), wcslen(fileDlg.GetPathName()) * sizeof(TCHAR));
		file.Close();

		//CStdioFile mFile; 
		//CFileException fileException; 
		//if (!mFile.Open(fileDlg.GetPathName(), CFile::modeCreate | CFile::modeWrite | CFile::typeBinary)) { 
		//	AfxMessageBox(_T("文件路径找不到，打开文件失败")); return; 
		//} 
		//const int UNICODE_TXT_FLG = 0xFEFF; 
		//char d = '\t'; 
		//CString cs = _T("角度"); 
		//cs += d; 
		//cs += _T("权值\r\n"); 
		//mFile.Write(&UNICODE_TXT_FLG, 2); 
		//mFile.Write(cs.GetBuffer(10), cs.GetLength() * 2);
		//mFile.Close();
	}
}
#undef UNICONE_TEXT

void CFileView::OnRegRead()
{
	// TODO: Add your command handler code here
	//LONG lValue;
	//RegQueryValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\C++ Lessons\\admin", NULL, &lValue);
	//wchar_t* pBuf = new wchar_t[lValue];
	//RegQueryValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\C++ Lessons\\admin", pBuf, &lValue);
	//MessageBoxW(pBuf, L"Reg", 0);

	HKEY hkey;
	RegOpenKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\C++ Lessons\\admin", &hkey);
	DWORD dwType;
	DWORD dwValue;
	DWORD dwAge;
	RegQueryValueEx(hkey, L"age", 0, &dwType, (LPBYTE)&dwAge, &dwValue);
	CString str;
	str.Format(L"age = %d", dwAge);
	MessageBox(str);
	

}


void CFileView::OnRegWrite()
{
	// TODO: Add your command handler code here
	HKEY hkey;
	//DWORD dwDisposition; 
	int err;
	//err = RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\C++ Lessons\\admin", 0, NULL, REG_OPTION_NON_VOLATILE, 0, NULL, &hkey, &dwDisposition);
	err = RegCreateKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\C++ Lessons\\admin", &hkey);
	err = GetLastError();
	err = RegSetValue(hkey, NULL, REG_SZ, L"ted", wcslen(L"ted") * sizeof(TCHAR));
	err = GetLastError();
	DWORD dwAge = 30; 
	err = RegSetValueEx(hkey, L"age", 0, REG_DWORD, (const BYTE*)&dwAge, 4);
	err = GetLastError();
	err = RegCloseKey(hkey);
	err = GetLastError();
}
