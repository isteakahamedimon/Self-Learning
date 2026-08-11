#include<iostream>
int main()
{

    int a = 5;
    const int& b = a;

    b = 6;      // ERROR
    std::cout << "a:" << a << " b:" << b << std::endl;
    

    return 0;
}
