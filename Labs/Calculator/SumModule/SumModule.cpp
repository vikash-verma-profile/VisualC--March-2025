#include "pch.h"
#include "SumModule.h"

extern "C" {
    SUMMODULE_API int Add(int a, int b) {
        return a + b;
    }
}
