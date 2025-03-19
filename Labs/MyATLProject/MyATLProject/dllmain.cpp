// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "MyATLProject_i.h"
#include "dllmain.h"

CMyATLProjectModule _AtlModule;

class CMyATLProjectApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMyATLProjectApp, CWinApp)
END_MESSAGE_MAP()

CMyATLProjectApp theApp;

BOOL CMyATLProjectApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CMyATLProjectApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
