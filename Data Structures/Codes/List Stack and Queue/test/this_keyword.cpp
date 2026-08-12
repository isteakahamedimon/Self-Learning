#include<iostream>

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

        //std::cout << *this << std::endl;       
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
