#include <iostream>
#include <set>
#include <map>
using namespace std;

int main6()
{
	set<int> s = { 3,2,5,1 };
	map<int, string> m{ {1,"C#"},{2,"oracle"},{3,"c++"} };

	for (auto x : s) {
		cout << x << " ";
	}
	cout<< "\n";
	for (auto& x : m) {
		cout << x.first << " " << x.second<<"\n";
	}
	return 0;
}