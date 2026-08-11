#include <iostream>

class Student {
    private:
        // int ID;
    public:
        std::string name;
        int age;

        void insert(std::string name, int age) {
            this->name = name;
            this->age = age;
        }
        void printIdentity() {
            std::cout << "name: " << name << " age: " << age << "\n";
        }
};

int main()
{
    Student Isteak;
    Isteak.insert("Isteak Ahamed Imon", 23);
    Isteak.printIdentity();


    return 0;
}
