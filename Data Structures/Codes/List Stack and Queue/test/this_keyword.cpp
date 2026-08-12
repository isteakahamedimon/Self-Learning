#include<iostream>

class Identity
{
    private:
        // int id;
    public:
        std::string name;
        int age;

        Identity(std::string name, int age)
            : name(name), age(age) {
             // this is a pointer and it holds the address of the object 
               std::cout << this << std::endl;
            }

        void showIdentity() {
            std::cout << "Name: " << this->name << " Age: " << this->age << std::endl;

            std::cout << this << std::endl;

        }

};

int main()
{
    Identity me("Isteak", 23);
    me.showIdentity();

    return 0;
}
