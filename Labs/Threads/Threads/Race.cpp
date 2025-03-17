#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;// creating for synchorization

void increment() {
	for (size_t i = 0; i < 1000000; i++)
	{
		lock_guard<mutex> lock(mtx); //locks automatically
		++counter;//no sync
	}
}

int  main2() {
	thread t1(increment);
	thread t2(increment);

	t1.join();
	t2.join();
	cout << "Final; counter value :" << counter << endl;

	return 0;
}