#include "pch.h"
#include <windows.h>
#include <iostream>



#define EXPORT extern "C" __declspec(dllexport)

EXPORT void HelloWorld() {
	std::cout << "Hello from DLL !!" << std::endl;
}