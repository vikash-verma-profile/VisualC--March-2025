#pragma once

#ifdef SUMMODULE_EXPORTS
#define SUMMODULE_API __declspec(dllexport)
#else
#define SUMMODULE_API __declspec(dllimport)
#endif

extern "C" {
    SUMMODULE_API int Add(int a, int b);
}
