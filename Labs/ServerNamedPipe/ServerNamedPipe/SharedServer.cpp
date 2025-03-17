#include <iostream>
#include <windows.h>

using namespace std;
int main()
{

	HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,256,L"MySharedMemory");

	if (!hMapFile) {
		cerr << "Failed to create a shared memory \n";
		return 1;
	}
	LPVOID pBuf = MapViewOfFile(hMapFile,FILE_MAP_ALL_ACCESS,0,0,256);
	if (!pBuf) {
		CloseHandle(hMapFile);
		return 1;
	}
	string message = "Hello from server ! \n";
	memcpy(pBuf,message.c_str(),message.size()+1);
	cout << "Message written to shared memory \n";
	cin.get();//wait for client to read

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
	return 0;
}
