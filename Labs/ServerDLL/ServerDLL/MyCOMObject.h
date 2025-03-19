#pragma once
#include "IMyInterface.h"
#include <iostream>
#include <objbase.h>

using namespace std;
static const CLSID CLSID_MyCOMObject = {
0x824c14dc, 0x692, 0x4671, {0xb7, 0xe7, 0xa4, 0xae, 0xdf, 0xf8, 0x20, 0x3b }
};
//__declspec(uuid("8ff62f5b-bde0-4ffc-8a3a-b501023a2884"))
class MyComObject :public IMyInterface {
private:
	ULONG refCount;
public:
	MyComObject() :refCount(1) {

	}

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) override {
		if (riid == IID_IUnknown || riid == IID_IMyInterface) {
			*ppvObject = static_cast<IMyInterface*>(this);
			AddRef();
			return S_OK;
		}
		*ppvObject = nullptr;
		return E_NOINTERFACE;
	}

	ULONG STDMETHODCALLTYPE AddRef() override {
		return ++refCount;
	}
	ULONG STDMETHODCALLTYPE Release() override {
		if (--refCount == 0) {
			delete this;
			return 0;
		}
		return refCount;
	}

	HRESULT STDMETHODCALLTYPE DoSomething() override {
		cout << "Hello I am from COM Object" << endl;
		return S_OK;
	}
};

