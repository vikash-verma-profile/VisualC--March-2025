#include <iostream>
#include <windows.h>


using namespace std;
int main2()
{

	HANDLE hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE,L"MySharedMemory");


	if (!hMapFile) {
		cerr << "could not open shared memory \n";
		return 1;
	}
	LPVOID pBuf = MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 256);
	if (!pBuf) {
		CloseHandle(hMapFile);
		return 1;
	}
	cout << "Message from shared memory: " << (char*)pBuf << "\n";
	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
	return 0;
}
