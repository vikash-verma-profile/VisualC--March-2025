#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> Acounter(0);


void incrementnew() {
	for (int i = 0; i < 1000000; i++)
	{
		Acounter.fetch_add(1,memory_order_relaxed);
		//++counter;//no sync
	}
}

int  main3() {
	thread t1(incrementnew);
	thread t2(incrementnew);

	t1.join();
	t2.join();
	cout << "Final; counter value :" << Acounter << endl;

	return 0;
}