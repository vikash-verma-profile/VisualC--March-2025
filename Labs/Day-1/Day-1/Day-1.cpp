#include <iostream>

int main1()
{
    // <data type> * pointer_name
    /*
        
    */
    int a = 5;
    int* ptr;
   
    ptr = &a;
    std::cout << ptr<<"\n";
    std::cout << a<< "\n";
    std::cout << *ptr << "\n";
    return 0;
}

