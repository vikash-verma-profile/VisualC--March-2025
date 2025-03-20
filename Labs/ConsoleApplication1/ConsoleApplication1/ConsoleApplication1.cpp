#include <windows.h>
#include <iostream>
using namespace std;

typedef void(*HelloWordFunc)();

int main()
{
    HMODULE hDLL = LoadLibrary(L"MyLibrary.dll");
    if (!hDLL) {
        cerr << "DLL failed to load" << endl;
        return 1;
    }

    HelloWordFunc Helloworld = (HelloWordFunc)GetProcAddress(hDLL,"HelloWorld");
    if (!Helloworld) {
        cerr << "Failed to get function address" << endl;
        FreeLibrary(hDLL);
        return 1;
    }
    Helloworld();
    FreeLibrary(hDLL);
    return 0;
}

