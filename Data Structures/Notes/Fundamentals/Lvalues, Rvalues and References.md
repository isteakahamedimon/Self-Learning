**lvalue reference** holds an address and **rvalue reference** holds a temporary value

```
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
```


`const` declaration can take both lvalue and rvalue references. && is also used for revalue reference.

```
const int& a = 8;
int&& a = 8;
```
