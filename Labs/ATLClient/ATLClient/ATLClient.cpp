#include <iostream>
#include <windows.h>
#include <atlstr.h>
#include <atlbase.h>
#include <atlcomcli.h>
#include "MyATLProject_i.h"

using namespace std;
int main()
{
    CoInitialize(NULL);
    CComPtr<IMyComObject> pCOmObj;
    HRESULT hr = pCOmObj.CoCreateInstance(CLSID_CMyComObject);
    if (SUCCEEDED(hr)) {
        pCOmObj->ShowMessage(CComBSTR(L"Hello from COM !!"));
    }
    else {
        cout << hr;
    }
    CoUninitialize();
    return 0;
}
