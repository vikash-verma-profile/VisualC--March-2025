#include <iostream>
#include <thread>

using namespace std;

void SampleFunction() {
    cout << "Hello!! this is a sample" << endl;
}

class Functor {
public:
    void operator() () {
        cout << "Thread using a functor" << endl;
    }
};
int main1()
{
    //1. Create using a function pointer
    //create a thread that calles a method
    //thread newThread(SampleFunction);


    // create a thread using lambda
   /* thread newThread([] {
        cout << "Hello!! this is a sample" << endl;
        });*/


    std::thread newThread((Functor()));
    newThread.join();
    cout << "This is a message from main thread"<<endl;
    return 0;
}

