#include<iostream>
#include<string>

class cse22 {
    public:
        int height = 50;
        std::string favColor = "blue";
        static int age;
        static int bhf;
        static const int highestWeight = 80;
};

int cse22::age = 23;
int cse22::bhf = 32;

int main()
{
    cse22::age = 25;
    cse22::bhf = 52;
    // std::cout << cse22::age << "\n";
    // std::cout << cse22::highestWeight << "\n";

    cse22 isteak, ahamed;
    // std::cout << isteak.age << " " << isteak.highestWeight << "\n";

    // std::cout << "Address of cse22::age: " << &cse22::age << "\n";
    // std::cout << "Address of isteak.age: " << &isteak.age << "\n";
    // std::cout << "Address of ahamed.age: " << &ahamed.age << "\n";

    std::cout << "Address of isteak: " << &isteak << "\n";
    std::cout << "Address of isteak.height: " << &isteak.height << "\n";
    std::cout << "Address of isteak.color: " << &isteak.favColor << "\n";
   
    std::cout << std::endl;

    std::cout << "Address of ahamed: " << &ahamed<< "\n";
    std::cout << "Address of ahamed.height: " << &ahamed.height << "\n";
    std::cout << "Address of ahamed.color: " << &ahamed.favColor << "\n";

    
    std::cout << "\nPrinting all the static variables: \n";
    std::cout << "Address of static isteak.age: " << &isteak.age << "\n";
    std::cout << "Address of static isteak.bhf: " << &isteak.bhf << "\n";

    std::cout << "Address of static ahamed.age: " << &ahamed.age << "\n";
    std::cout << "Address of static ahamed.bhf: " << &ahamed.bhf << "\n";


    return 0;
}
