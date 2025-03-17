#include <iostream>
#include <thread>
#include <shared_mutex>
#include <chrono>

using namespace std;


// muliple threads to read 
// only one thread to write
// Online Library
shared_mutex book_mutex;
string bookContent = "C++ Concurrency Guide";//shared resource

void readBook(const string& user) {
	cout << user << "is reading"<<bookContent<< "\n";
	this_thread::sleep_for(chrono::seconds(1)); //simulate reading time
}
void editBook(const string& editor) {
	cout << editor << "is editing the book... \n";
	this_thread::sleep_for(chrono::seconds(1));
	bookContent = "Advanced c++ Concurrency";
	cout << editor << "finished edititing !\n";
}

int main() {
	thread reader1(readBook, "Vikash Verma");
	thread reader2(readBook, "Rohit Kumar");
	thread writer(editBook, "Editor");
	reader1.join();
	reader2.join();
	writer.join();
	return 0;

}