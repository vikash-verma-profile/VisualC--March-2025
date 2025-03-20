#pragma once
#include "resource.h"     
#include "DemoSnap_i.h"
#include <mmc.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CHelloSnapin

class ATL_NO_VTABLE CHelloSnapin :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CHelloSnapin, &CLSID_HelloSnapin>,
    public IDispatchImpl<IHelloSnapin, &IID_IHelloSnapin, &LIBID_DemoSnapLib, 1, 0>,
    public IComponentData,
    public IComponent
{
public:
    CHelloSnapin() {}

    DECLARE_REGISTRY_RESOURCEID(106)

    BEGIN_COM_MAP(CHelloSnapin)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IHelloSnapin)
        COM_INTERFACE_ENTRY(IComponentData)
        COM_INTERFACE_ENTRY(IComponent)
    END_COM_MAP()

    // IComponentData methods
    STDMETHOD(Initialize)(LPUNKNOWN pUnknown);
    STDMETHOD(CreateComponent)(LPCOMPONENT* ppComponent);
    STDMETHOD(Notify)(LPDATAOBJECT lpDataObject, MMC_NOTIFY_TYPE event, LPARAM arg, LPARAM param);
    STDMETHOD(Destroy)(void);
    STDMETHOD(QueryDataObject)(MMC_COOKIE cookie, DATA_OBJECT_TYPES type, LPDATAOBJECT* ppDataObject);
    STDMETHOD(GetDisplayInfo)(SCOPEDATAITEM* pScopeDataItem);
    STDMETHOD(CompareObjects)(LPDATAOBJECT lpDataObjectA, LPDATAOBJECT lpDataObjectB);

    // IComponent methods
    STDMETHOD(Initialize)(LPCONSOLE lpConsole);
    STDMETHOD(Destroy)(MMC_COOKIE cookie);
    STDMETHOD(GetResultViewType)(MMC_COOKIE cookie, LPOLESTR* ppViewType, long* pViewOptions);
    STDMETHOD(GetDisplayInfo)(RESULTDATAITEM* pResultDataItem);
   
    DECLARE_PROTECT_FINAL_CONSTRUCT()

    HRESULT FinalConstruct() { return S_OK; }
    void FinalRelease() {}
};


OBJECT_ENTRY_AUTO(__uuidof(HelloSnapin), CHelloSnapin)
