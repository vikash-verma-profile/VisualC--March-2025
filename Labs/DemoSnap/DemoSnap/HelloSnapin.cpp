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

STDMETHODIMP CHelloSnapin::Destroy(void) {
    return S_OK;
}

STDMETHODIMP CHelloSnapin::GetDisplayInfo(SCOPEDATAITEM* pScopeDataItem) {
    return E_NOTIMPL;
}


// IComponent Methods
STDMETHODIMP CHelloSnapin::Initialize(LPCONSOLE lpConsole) {
    return S_OK;
}

STDMETHODIMP CHelloSnapin::Notify(LPDATAOBJECT lpDataObject, MMC_NOTIFY_TYPE event, LPARAM arg, LPARAM param) {
    return S_OK;
}

STDMETHODIMP CHelloSnapin::Destroy(MMC_COOKIE cookie) {
    return S_OK;
}

STDMETHODIMP CHelloSnapin::GetResultViewType(MMC_COOKIE cookie, LPOLESTR* ppViewType, long* pViewOptions) {
    return E_NOTIMPL;
}

STDMETHODIMP CHelloSnapin::QueryDataObject(MMC_COOKIE cookie, DATA_OBJECT_TYPES type, LPDATAOBJECT* ppDataObject) {
    return E_NOTIMPL;
}

STDMETHODIMP CHelloSnapin::GetDisplayInfo(RESULTDATAITEM* pResultDataItem) {
    return E_NOTIMPL;
}

STDMETHODIMP CHelloSnapin::CompareObjects(LPDATAOBJECT lpDataObjectA, LPDATAOBJECT lpDataObjectB) {
    return E_NOTIMPL;
}

