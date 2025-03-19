#pragma once
#include "IMyInterface.h"
#include <iostream>
#include <objbase.h>

using namespace std;
static const IID CLSID_MyCOMObject = {

};
__declspec(uuid("8ff62f5b-bde0-4ffc-8a3a-b501023a2884"))
class MyComObject :public IMyInterface {
private:
	ULONG refCount;
public:
	MyComObject() :refCount(1) {

	}

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,void** ppvObject) override {
		if (riid==IID_IUnknown || riid == IID_IMyInterface) {
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

//Factory function to create the com object

extern "C" __declspec(dllexport) HRESULT CreateInstance(REFCLSID clsid,REFIID iid,void** ppv) {
	if (clsid == CLSID_MyCOMObject) {
		MyComObject* obj = new MyComObject();
		return obj->QueryInterface(iid,ppv);
	}

	return E_NOINTERFACE;
}