#pragma once

#include <atlbase.h>  // Base ATL classes
#include <atlcom.h>   // COM support
#include "resource.h"


DEFINE_GUID(CLSID_MyComObject,
    0x06F0CFB7, 0x7715, 0x4886, 0xB8, 0xF7, 0x0B, 0x2F, 0xB4, 0xCF, 0x0C, 0x7A);

[uuid("06F0CFB7-7715-4886-B8F7-0B2FB4CF0C7A")]
interface IMyComObject : IDispatch {
   HRESULT ShowMessage(BSTR message);
};
[uuid("E44E93DD-D430-42D8-831A-892B632D3115")]
class ATL_NO_VTABLE CMyComObject :
    public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
    public ATL::CComCoClass<CMyComObject, &CLSID_MyComObject>,
    public IMyComObject
{
public:
    DECLARE_REGISTRY_RESOURCEID(IDR_MYCOMOBJECT)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CMyComObject)
        COM_INTERFACE_ENTRY(IMyComObject)
        COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    STDMETHOD(ShowMessage)(BSTR message);
};
