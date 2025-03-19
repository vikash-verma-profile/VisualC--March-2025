#include "pch.h"

STDAPI DLLRegisterServer(void) {
	HRESULT hr = _AtlModule.DllRegisterServer();
	if (FAILED(hr)) return hr;

	ATL::CRegKey key;
	key.Create(HKEY_LOCAL_MACHINE,_T(""));
	key.SetStringValue(_T("Name String"), _T("My Custom MMC Snap in"));
	key.SetStringValue(_T("Provider"), _T("Sample Company"));
	key.SetStringValue(_T("Version"), _T("1.0"));
	key.SetStringValue(_T("Description"), _T("My First MMC Snap in"));
	return S_OK;


}



