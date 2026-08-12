#include<iostream>

int& func(int& var)
{
    std::cout << "Address of var inside func: " << &var << std::endl;
    return var;
}

int main()
{
    int var = 5;
    std::cout << "Address of var inside main: " << &var << std::endl;

    int& new_var = func(var);
    std::cout << "Address of new_var inside main: " << &new_var << std::endl;


    return 0;
}
