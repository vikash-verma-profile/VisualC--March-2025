// dllmain.h : Declaration of module class.

class CDEMOSNAPINModule : public ATL::CAtlDllModuleT< CDEMOSNAPINModule >
{
public :
	DECLARE_LIBID(LIBID_DEMOSNAPINLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DEMOSNAPIN, "{17902e7b-8799-44c1-8ef0-6f203d85cada}")
};

extern class CDEMOSNAPINModule _AtlModule;
