#include "pch.h"
#include "MyModuleFunctions.h"

extern "C" {
    // Correct definition — no need to redeclare with extern "C" here
    int Add(int a, int b) {
        return a + b;
    }
}
