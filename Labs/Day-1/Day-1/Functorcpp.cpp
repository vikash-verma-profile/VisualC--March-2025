#include <iostream>
#include <vector>

using namespace std;

int main()
{
	plus<int> add;//functor object
	minus<int> minus;
	multiplies<int> mult;
	int result3 = mult(10, 20);
	int result2 = minus(30,40);
	int result = add(10, 20);
	cout << "SUM :" << result<<endl;
	cout << "Minus :" << result2 << endl;
	cout << "Mult :" << result3;
	return 0;
}