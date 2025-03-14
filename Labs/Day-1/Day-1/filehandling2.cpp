#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	fstream file("example1.txt",ios::in | ios::out | ios::app);
	if (!file) {
		cout << "Error in opening file" << endl;
		return 1;
	}
	file << "Hello ,This is a test file" << endl;
	file << "Writing to a file in c++" << endl;

	
	cout << "File written successfully" << endl;;
	
	file << "This is an sample appended line" << endl;
	cout << "File appended successfully" << endl;
	file.seekg(0); //move file pointer to th ebegining for reading
	
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}
	file.close();
	remove("example1.txt");
	return 0;
}