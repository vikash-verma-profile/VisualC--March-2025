#include <iostream>
#include <windows.h>
#define Queue_NAME L"\\\\.\\mailslot\\MyMailslot"


using namespace std;
int main()
{

	HANDLE hQueue = CreateMailslot(Queue_NAME, 0,MAILSLOT_WAIT_FOREVER,NULL);

	if (hQueue==INVALID_HANDLE_VALUE) {
		cerr << "Failed to create a message queue \n";
		return 1;
	}
	char buffer[128];
	DWORD bytesRead;
	while (true) {
		if (ReadFile(hQueue, buffer, sizeof(buffer), &bytesRead, NULL)) {
			cout << "Recieved: " << buffer << " \n";
		}
	}
	CloseHandle(hQueue);
	return 0;
}
