#pragma once

#include <windows.h>
#include <objbase.h>




static const IID IID_IMyInterface = {
	
};
__declspec(uuid("ddb76e28-5eb7-4d2b-bd9d-eeb1450edb7e"))
class IMyInterface :public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE DoSomething() = 0;
};