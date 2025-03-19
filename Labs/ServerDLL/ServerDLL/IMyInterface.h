#pragma once

#include <windows.h>
#include <objbase.h>

static const IID IID_IMyInterface = {
	0x8d96cc09, 0xfbb8, 0x4eed, {0xb4, 0xf3, 0x1f, 0xee, 0x7b, 0x55, 0xff, 0x14 }
};
//__declspec(uuid("ddb76e28-5eb7-4d2b-bd9d-eeb1450edb7e"))
class IMyInterface :public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE DoSomething() = 0;
};