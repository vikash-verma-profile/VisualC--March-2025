#include <iostream>

using namespace std;

//try catch and throw
void safeFunction() noexcept {
	cout << "This function will never throw exceptions";
}
int main10()
{
	/*int a, b;
	cout << "Enter two numbers";
	cin >> a >>b;*/
	try {
		/*if (b == 0) {
			throw runtime_error("Division by zero is not allowed");
		}
		cout << "Result is :" << a / b << endl;
		*/
		throw 42;
	}
	catch (int e) {
		cout << "Caught an integer exception" << e << endl;
	}
	catch (const char* msg) {
		cout << "expection caught " << msg << endl;
	}
	catch (...) {
		cout << "Cauhgt an unkown execption" << endl;
	}

	return 0;
}