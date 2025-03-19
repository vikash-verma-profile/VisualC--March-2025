#include "pch.h"
#include "MyCOMObject.h"

//Factory function to create the com object

extern "C" __declspec(dllexport) HRESULT CreateInstance(REFCLSID clsid, REFIID iid, void** ppv) {
	if (clsid == CLSID_MyCOMObject) {
		MyComObject* obj = new MyComObject();
		return obj->QueryInterface(iid, ppv);
	}

	return E_NOINTERFACE;
}