include<iostream>
int main()
{
    int a = 5;
    int& b = a;     // correct lavalue assignment

    int& c = 8;     // ERROR since c is a reference
                    // of an integer variable whereas
                    // 8 is a const value
    
    const int& c = 8;   // const declarations can take rvalues

    int&& c = 8;        // && is used for rvalue declaration
    

    int& d = a + c;     // ERROR. Although a and c are individually references but "a+c" is not



    std::cout << "a:" << a << " b:" << b << "\n";

    return 0;
}
