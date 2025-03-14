#include <iostream>

using namespace std;

class MyException :public exception {
public:
	const char* what() const noexcept override {
		return "Custom exception occured";
	}
};

int main()
{
	try{
		throw MyException();
	}
	catch (const exception& e) {
		cout << "Exception :" << e.what() << endl;
	}
	return 0;
}