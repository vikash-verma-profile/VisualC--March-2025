#include <iostream>
#include <windows.h>
#define PIPE_NAME L"\\\\.\\pipe\\MyPipe"

using namespace std;
int main1()
{
   
	HANDLE hPipe = CreateNamedPipe(PIPE_NAME,PIPE_ACCESS_DUPLEX,PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,1,1024,1024,0,NULL);

	if (hPipe == INVALID_HANDLE_VALUE) {
		cerr << "Failed to create a named piple \n";
		return 1;
	}
	cout << "Waiting for client connection.. \n";
	if (ConnectNamedPipe(hPipe, NULL)) {
		char buffer[128];
		DWORD bytedRead;
		ReadFile(hPipe,buffer,sizeof(buffer),&bytedRead,NULL);
		cout << "Recieved :" << buffer << "\n";
		string response = "Message recieved !";
		DWORD bytesWritten;
		WriteFile(hPipe, response.c_str(), response.length()+1, &bytesWritten, NULL);
	}
	CloseHandle(hPipe);
	return 0;
}
