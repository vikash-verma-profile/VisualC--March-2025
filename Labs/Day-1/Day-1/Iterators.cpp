#include <iostream>
#include <vector>

using namespace std;

int main8()
{
	vector<int> v1 = { 1,2,3,4,5 };
	
	//declare an iterator

	vector<int>::iterator i1;

	for (i1= v1.begin(); i1!=v1.end(); ++i1)
	{
		cout << *i1 << " "; 
	}

	return 0;
}