#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main12()
{
	/*ofstream outfile("example.txt");
	if (!outfile) {
		cout << "Error in opening file" << endl;
		return 1;
	}
	outfile << "Hello ,This is a test file" << endl;
	outfile << "Writing to a file in c++" << endl;

	outfile.close();
	cout << "File written successfully";*/


	ofstream outfile("example.txt",ios::app);
	if (!outfile) {
		cout << "Error in opening file" << endl;
		return 1;
	}
	outfile << "This is an sample appended line" << endl;
	outfile.close();
	cout << "File written successfully" << endl;

	ifstream infile("example.txt");
	if (!infile) {
		cout << "Error in opening file" << endl;
		return 1;
	}
	string line;
	while (getline(infile, line))
	{
		cout << line << endl;
	}
	infile.close();
	return 0;
}