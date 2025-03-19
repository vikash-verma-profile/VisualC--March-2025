#pragma once
#include <atlbase.h>  // Base ATL classes
#include <atlcom.h>   // COM support

[object,uuid("06F0CFB7-7715-4886-B8F7-0B2FB4CF0C7A"),dual,nonextensible,pointer_default(unique)]
interface IMyComObject :IDispatch {
	[id(1)] HRESULT ShowMessage([in] BSTR message);
};

class ATL_NO_VTABLE CMyComObject :
    public CComObjectRootEx<CComSingleThreadModel>,  // Ensure this is correct
    public CComCoClass<CMyComObject, &CLSID_MyComObject>,
    public IMyComObject
{
public:
    DECLARE_REGISTRY_RESOURCEID(IDR_MYCOMOBJECT)

    BEGIN_COM_MAP(CMyComObject)
        COM_INTERFACE_ENTRY(IMyComObject)
    END_COM_MAP()

    STDMETHOD(ShowMessage)(BSTR message);
};

