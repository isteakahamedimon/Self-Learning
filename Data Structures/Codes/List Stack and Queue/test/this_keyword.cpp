#include<iostream>

class Identity;

void PrintIdentity(Identity* I);

class Identity
{
    private:
        // int id;
    public:
        std::string name;
        int age;

        Identity(std::string name, int age)
        {
             // this is a pointer and it holds the address of the object 
             this->name = name;
             this->age = age;

             PrintIdentity(this);
        }

        // A class body can only contain declarations(member variables, member function declarations/definitions, nested types(a class, struct, enum, or even a typedef/using alias). Loose statement like the following one has to be inside a function. This will throw a Compilation Error. So, basically this statement is trying to interprete std::cout as a declaration. This can also be fixed by defining <<'s operator overloading.
        std::cout << this << std::endl;       
};

void PrintIdentity(Identity* I)
{
    std::cout << I->name << " " << I->age << "\n";
}

int main()
{
    Identity me("Isteak", 23);

    return 0;
}
