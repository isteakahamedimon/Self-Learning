#include<iostream>
#include<string>
using namespace std;


int main() {
    
    int x = 5;
    int& y = x;

    cout << "x:" << x << " y:" << y << "\n";
    cout << "*x:" << &x << " *y:" << &y << "\n";

    return 0;
}
