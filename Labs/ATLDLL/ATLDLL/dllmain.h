// dllmain.h : Declaration of module class.

class CATLDLLModule : public ATL::CAtlDllModuleT< CATLDLLModule >
{
public :
	DECLARE_LIBID(LIBID_ATLDLLLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLDLL, "{a559496d-fd69-419d-b111-be9336eb42ba}")
};

extern class CATLDLLModule _AtlModule;
