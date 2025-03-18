#pragma once

#ifdef MYMODULEFUNCTIONS_EXPORTS
#define MYMODULEFUNCTIONS_API __declspec(dllexport)
#else
#define MYMODULEFUNCTIONS_API __declspec(dllimport)
#endif

extern "C" {
    MYMODULEFUNCTIONS_API int Add(int a, int b);  // Correct declaration
}
