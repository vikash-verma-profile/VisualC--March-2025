#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
public:
	int empId;
	string employeeName;

	Employee(int id, string name)
	{
		empId = id;
		employeeName = name;
	}
};
void displayMenu() {
	cout << "Please select a opeartion : \n 1.Insert Employee\n 2.Update Employee\n 3.Delete Employee\n 4.List Employee\n 5.Exit\n";
}

void insertEmployee(vector<Employee>& employee) {
	int id;
	string name;
	cout << "Employee Id:";
	cin >> id;
	cout << "Enter Employee Name";
	getline(cin, name);
	employee.push_back(Employee(id, name));
	cout << "Employee Added Successfully";
}

void listEmployees(vector<Employee>& employee) {
	if (employee.empty()) {
		cout << "No employees found \n";
		return;
	}
	cout << "\n List of employees \n";
	for (const auto& emp:employee)
	{
		cout << "ID :" << emp.empId << "Name :" << emp.employeeName << endl;
	}
}
int main() {
	int choice;
	vector<Employee> employeeList;

	do {
		displayMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			insertEmployee(employeeList);
			break;
		case 5:
			cout << "Exiting program \n";
			break;
		default:
			cout << "Invalid choice!please try again\n";
		}
	} while (choice != 5);


	return 0;
}