#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


//mutex mtxP;
recursive_mutex rmtxP;

void recursiveFunctionP(int n) {
	rmtxP.lock();
	cout << "Recursive Depth : " << n << endl;
	if (n > 1) {
		recursiveFunctionP(n - 1);
	}
	rmtxP.unlock();
}

int main5() {
	thread t1(recursiveFunctionP, 5);
	t1.join();
	return 0;

}