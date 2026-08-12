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
             // 1. THE 'this' POINTER:
             // 'this' is a hidden pointer holding the memory address of the current object.
             // We use 'this->' here to resolve "shadowing" (telling the compiler we mean 
             // the member variables, not the constructor parameters with the same names).
             this->name = name;
             this->age = age;

             // We can also pass the 'this' pointer to external functions to give them 
             // direct access to this specific object instance.
             PrintIdentity(this);
        }

        // 2. CLASS BODY RULES:
        // A class body can only contain declarations (member variables, member function 
        // declarations/definitions, nested types). Loose execution statements like the 
        // one below MUST be inside a function. Otherwise, the compiler tries to interpret 
        // it as a declaration and throws a Compilation Error.
        // std::cout << this << std::endl;

        // 3. MEMBER FUNCTION OPERATOR OVERLOAD:
        // Because this is defined as a member function of the Identity class, the object 
        // calling it MUST be on the left side of the operator. 
        std::ostream& operator<<(std::ostream& os)
        {
            // Prints the memory address of this specific object instance
            os << this; 
            
            // 4. CHAINING:
            // We MUST return the stream (os) by reference to allow chaining (e.g., << std::endl).
            // If this function returned 'void', the chain would break.
            return os;
        }
};

void PrintIdentity(Identity* I)
{
    std::cout << I->name << " " << I->age << "\n";
}

int main()
{
    Identity me("Isteak", 23);
    
    // std::cout << me << std::endl; 
    // ^ ERROR EXPLANATION: This fails because 'std::cout' is on the left. The compiler looks 
    // for a member function inside the 'ostream' class that takes an 'Identity' object, 
    // which doesn't exist.

    // 5. THE BACKWARDS SYNTAX:
    // SUCCESS: Because operator<< is a member of Identity, the Identity object ('me') 
    // must be on the left to trigger it. This translates to: me.operator<<(std::cout)
    me << std::cout << std::endl; 
    
    // 6. HOW THE CHAIN EXECUTES:
    // Step A: `me << std::cout` executes first. It prints the address and RETURNS `std::cout`.
    // Step B: The statement simplifies to `std::cout << std::endl;`.
    // Step C: `std::endl` is actually a function pointer. The standard library accepts it, 
    // executes it, prints a newline, and flushes the output buffer.
    
    // 7. COMPETITIVE PROGRAMMING FAST I/O TIP: 
    // `std::endl` calls `.flush()`, which forces an expensive system call to write to the console. 
    // To avoid Time Limit Exceeded (TLE) errors in algorithms, always use `'\n'` instead of `std::endl`.

    return 0;
}
