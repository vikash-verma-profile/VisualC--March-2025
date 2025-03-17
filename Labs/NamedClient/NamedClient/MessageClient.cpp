#include <iostream>
#include <windows.h>
#define Queue_NAME L"\\\\.\\mailslot\\MyMailslot"

using namespace std;

int main()
{

	HANDLE hQueue = CreateFile(Queue_NAME, GENERIC_WRITE,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);


	if (hQueue==INVALID_HANDLE_VALUE) {
		cerr << "Failed to connect to messag queue \n";
		return 1;
	}
	string message = "Hello from client !";

	DWORD byteswritten;

	WriteFile(hQueue,message.c_str(),message.length()+1,&byteswritten,NULL);
	CloseHandle(hQueue);
	return 0;
}
