#include <iostream>
#include <vector>

int main() {

	std::vector<int> v1;//empty vector
	std::vector<int> v2(5);//vector of size 5 with default values 0
	std::vector<int> v3(5,100);//vector of size 5 with default values 100
	std::vector<int> v4 = { 1,2,3,4,5 };

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.pop_back(); //remove the last element

	std::cout << v1[0]<<"\n";
	std::cout << v1.at(1) << "\n";
	std::cout << v1.front() << "\n";
	std::cout << v1.back() << "\n";

	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i]<< " ";
	}

	std::cout << "\n";
	for (int num:v3) {
		std::cout << num << " ";
	}
	return 0;
}