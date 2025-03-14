#include <iostream>
#include <vector>


class Employee {
public:
	int EmpID;
	char EmployeeName[10];

};
int main() {
	int choice;
	std::cout << "Please select a opeartion : \n 1.Insert Employee\n 2.Update Employee\n 3.Update Employee\n 4.Delete Employee\n 5.List Employee\n 6.Exit\n";
	std::vector<Employee> employeeList;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		//insert operation
	default:
		break;
	}
	return 0;
}