#include <iostream>
#include <windows.h>
#include "IMyInterface.h"

using namespace std;

typedef HRESULT(*CreateInstanceFunc)(REFCLSID, REFIID, void**);

int main()
{

	HMODULE hDLL = LoadLibrary(L"ServerDLL.dll");
	if (!hDLL) {
		cerr << "Failed to load COM server dll"<<endl;
		return -1;
	}

	//get instance

	CreateInstanceFunc CreateInstance = (CreateInstanceFunc)GetProcAddress(hDLL,"CreateInstance");
	if (!CreateInstance) {
		cerr << "Failed to get CreateInstance function" << endl;
		FreeLibrary(hDLL);
		return -1;
	}
	IMyInterface* pMyObj = nullptr;
	HRESULT hr = CreateInstance(CLSID_MyCOMObject,IID_IMyInterface,(void**)&pMyObj);
	if (SUCCEEDED(hr)) {
		pMyObj->DoSomething();
		pMyObj->Release();
	}
	else {
		cerr << "Failed to create a com object" << endl;
	}
	FreeLibrary(hDLL);
	return 0;
}

