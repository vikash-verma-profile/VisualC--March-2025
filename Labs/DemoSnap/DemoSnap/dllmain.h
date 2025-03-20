// dllmain.h : Declaration of module class.

class CDemoSnapModule : public ATL::CAtlDllModuleT< CDemoSnapModule >
{
public :
	DECLARE_LIBID(LIBID_DemoSnapLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DEMOSNAP, "{bbe6af48-5b9c-43b7-975a-458bd00d5d5a}")
};

extern class CDemoSnapModule _AtlModule;
