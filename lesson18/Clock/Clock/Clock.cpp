// Clock.cpp : Implementation of CClockApp and DLL registration.

#include "stdafx.h"
#include "Clock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CClockApp theApp;

const GUID CDECL _tlid = { 0x4FD2DA21, 0x84C2, 0x4AC7, { 0xBE, 0xD4, 0x97, 0x57, 0x80, 0x6, 0xCB, 0x3B } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CClockApp::InitInstance - DLL initialization

BOOL CClockApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CClockApp::ExitInstance - DLL termination

int CClockApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
