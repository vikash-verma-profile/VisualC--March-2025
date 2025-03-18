#include "pch.h"
#include "Calculator.h"

STDMETHODIMP CCalculatorCom::Add(int a,int b,int* result) {
	*result = a + b;
	return S_OK;// S_OK means success
}