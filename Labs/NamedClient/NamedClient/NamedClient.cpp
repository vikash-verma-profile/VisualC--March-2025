#include <iostream>
#include <windows.h>
#define PIPE_NAME L"\\\\.\\pipe\\MyPipe"

using namespace std;
int main()
{

	HANDLE hPipe = CreateFile(PIPE_NAME, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);

	if (hPipe == INVALID_HANDLE_VALUE) {
		cerr << "Failed to connect to pipe \n";
		return 1;
	}
	string message = "Hello Server!";
	DWORD bytesWritten;
	
	WriteFile(hPipe,message.c_str(),message.length() + 1, &bytesWritten, NULL);
	char buffer[128];
	DWORD bytesRead;
	ReadFile(hPipe,buffer, sizeof(buffer), &bytesRead, NULL);
	cout << "Server response: " << buffer << "\n";
	CloseHandle(hPipe);
	return 0;
}
