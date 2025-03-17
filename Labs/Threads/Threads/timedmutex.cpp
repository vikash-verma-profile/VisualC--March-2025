#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;


timed_mutex ticket_mutex;

void bookTicket(const string &user) {
	cout << user << "is trying to book a ticket \n";

	if (ticket_mutex.try_lock_for(chrono::seconds(2))) {
		cout << user << " successfuly booked a tickect ! \n";
		this_thread::sleep_for(chrono::seconds(3));
		ticket_mutex.unlock();
	}
	else {
		cout << user << " coun't book a ticket. System is buzy ! \n";
	}
}

int main6() {
	thread user1(bookTicket, "Vikash Verma");
	thread user2(bookTicket, "Rohit Kumar");
	user1.join();
	user2.join();
	return 0;

}