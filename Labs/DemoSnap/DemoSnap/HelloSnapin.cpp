// HelloSnapin.cpp : Implementation of CHelloSnapin

#include "pch.h"
#include "HelloSnapin.h"


STDMETHODIMP CHelloSnapin::Initialize(LPUNKNOWN pUnknown) {
	MessageBox(NULL,L"Hello ,This is a sample SNAPIN!",L"MMC Snap-IN",MB_OK);
	return S_OK;
}
STDMETHODIMP CHelloSnapin::CreateComponent(LPCOMPONENT* ppComponent) {
	*ppComponent = this;
	AddRef();
	return S_OK;
}
STDMETHODIMP CHelloSnapin::DestroyComponent(void) {
	Release();
	return S_OK;
}

