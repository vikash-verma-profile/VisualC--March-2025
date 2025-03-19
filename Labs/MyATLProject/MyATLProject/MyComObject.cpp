#include "pch.h"
#include "MyComObject.h"
#include <atlstr.h>
#include <Windows.h>

STDMETHODIMP CMyComObject::ShowMessage(BSTR message) {
    MessageBoxW(NULL, message, L"COM Message", MB_OK);
    return S_OK;
}
