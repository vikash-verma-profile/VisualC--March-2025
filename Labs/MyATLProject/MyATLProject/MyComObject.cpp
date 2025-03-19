#include "pch.h"
#include "MyComObject.h"
#include <atlstr.h>  // CString for string handling
#include <iostream>

STDMETHODIMP CMyComObject::ShowMessage(BSTR message)
{
    // Convert BSTR to CString
    CString strMessage(message);

    // Display the message (for now, using std::wcout)
    std::wcout << L"COM Message: " << strMessage.GetString() << std::endl;

    return S_OK;
}
