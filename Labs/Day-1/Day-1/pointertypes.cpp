#include <iostream>
#include <stdio.h>

int main()
{

	//int* ptr = (int*)malloc(sizeof(int));

	//free(ptr);
	//std::cout << "memory freed \n";

	//ptr = NULL;//removing dangling pointer // NUll pointer
	//return 0;

	int x = 4;
	float y = 5.5;

	void* ptr;

	int* p; //wild pointer
	ptr = &x;

	std::cout << *((int*)ptr)<<"\n";
	ptr = &y;
	std::cout << *((float*)ptr);
	return 0;
}