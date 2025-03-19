#pragma once
using namespace ATL;

class ATL_NO_VTABLE CMySnapIn :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMySnapIn, &CLSID_MySnapIn>,
	public IComponent,
	public IComponentData {
public:

	CMySnapIn() {}

};