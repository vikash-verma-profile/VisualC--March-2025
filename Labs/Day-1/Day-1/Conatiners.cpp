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
	std::cout << "\n";
	v1.insert(v1.begin() + 1, 50);
	for (int num : v1) {
		std::cout << num << " ";
	}
	std::cout << "\n";
	std::cout << v1.size() << "\n";
	std::cout << v1.capacity() << "\n";
	v1.empty();
	v1.clear();
	std::cout << v1.size() << "\n";
	std::cout << v1.capacity() << "\n";;
	v1.shrink_to_fit();//reduce the capacity to match size
	std::cout << "after shrinking" << "\n";
	std::cout << v1.size() << "\n";
	std::cout << v1.capacity();
	v1.resize(10, 0);
	return 0;
}