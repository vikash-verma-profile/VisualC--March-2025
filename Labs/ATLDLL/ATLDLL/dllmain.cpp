// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "ATLDLL_i.h"
#include "dllmain.h"

CATLDLLModule _AtlModule;

class CATLDLLApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CATLDLLApp, CWinApp)
END_MESSAGE_MAP()

CATLDLLApp theApp;

BOOL CATLDLLApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CATLDLLApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
