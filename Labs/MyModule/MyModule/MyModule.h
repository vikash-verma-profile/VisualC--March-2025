// MyModule.h : main header file for the MyModule DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyModuleApp
// See MyModule.cpp for the implementation of this class
//

class CMyModuleApp : public CWinApp
{
public:
	CMyModuleApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
