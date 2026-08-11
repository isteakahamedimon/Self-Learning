#include<iostream>
#include<string>
using namespace std;

class Person {
    private:
        string m_name;
    public:
        Person(string name) : m_name(name) {}

        string getName1() {
            return m_name;
        }

        string& getName2() {
            return m_name;
        }

        const string& getName3() const {
            return m_name;
        }
};

int main() {

    /*
    Person p("Alice");

    string name = p.getName1();

    name = "Bob";

    cout << name << endl;
    cout << p.getName1() << endl;
    */

    /*
    Person p("Alice");

    string& name = p.getName2();

    name = "Bob";
    cout << name << endl;
    cout << p.getName2() << endl;
    */

    Person p("Alice");

    // const string& name = p.getName3();

    cout << p.getName3() << endl;

    Person i("Isteak");
    cout << i.getName3() << endl;


    return 0;
}
