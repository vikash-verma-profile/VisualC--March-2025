// dllmain.h : Declaration of module class.

class CMyATLProjectModule : public ATL::CAtlDllModuleT< CMyATLProjectModule >
{
public :
	DECLARE_LIBID(LIBID_MyATLProjectLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MYATLPROJECT, "{6a3a67dd-1625-4637-b7df-8e55719f88cc}")
};

extern class CMyATLProjectModule _AtlModule;
