#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int balance = 1000;// shared resource
mutex mtxBalance;
recursive_mutex rmtx;

void withdraw(int amount) {
	lock_guard<mutex> lock(mtxBalance);//locks the critical section
	if (balance >= amount) {
		cout << "Withdrawing " << amount << "....\n";
		balance -= amount;
		cout << "Remaining Balance: " << balance << endl;
	}
	else {
		cout << "Insufficient balance! \n";
	}
}

void recursiveFunction(int n) {
	if (n <= 0) return;
	rmtx.lock();
	cout << "Recursive Depth : " << n << endl;
	recursiveFunction(n-1);
	rmtx.unlock();
}

int main4() {
	/*thread husband(withdraw,700);
	thread wife(withdraw, 700);*/

	thread t1(recursiveFunction,5);

	/*husband.join();
	wife.join();*/
	t1.join();
	return 0;

}