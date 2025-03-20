// dllmain.h : Declaration of module class.

class CTestSnapModule : public ATL::CAtlDllModuleT< CTestSnapModule >
{
public :
	DECLARE_LIBID(LIBID_TestSnapLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TESTSNAP, "{1dd2b951-5f7f-4d70-81ba-fd460ebe9f07}")
};

extern class CTestSnapModule _AtlModule;
