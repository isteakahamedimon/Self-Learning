## 1. What is an Output Stream?
In C++, a stream is an abstraction that represents a flow of data. `std::cout` is a specific object of the `std::ostream` (output stream) class. It represents the standard output stream, which typically directs data to your terminal or console.

## 2. Operator Overloading (`<<`)
The `<<` symbol is the **stream insertion operator**. When you write `std::cout << 5;`, the C++ compiler translates this into a function call.

### Member vs. Non-Member Functions
- **Member Function:** If `<<` were a member of your custom class, the object would have to be on the left side: `obj << std::cout;`. This reads completely backwards and breaks the mental model of data flowing into the stream.
- **Non-Member Function:** To keep `std::cout` on the left side (`std::cout << obj;`), we overload `<<` as a standalone, non-member function. It takes the stream as its first parameter and your custom object as the second.

**Example:**
```cpp
#include <iostream>
#include <string>

class Identity {
public:
    std::string name;
    int age;
    
    Identity(std::string n, int a) : name(n), age(a) {}
};

// Non-member operator overload
std::ostream& operator<<(std::ostream& os, const Identity& obj) {
    os << "Name: " << obj.name << ", Age: " << obj.age;
    return os;
}

int main() {
    Identity me("Isteak", 23);
    std::cout << me << "\n";
    return 0;
}
```

## 3. How Chaining Works (Returning `os`)
When you write `std::cout << "Hello" << " World";`, C++ evaluates the expressions from left to right.

1. **Evaluation:** `std::cout << "Hello"` executes first.
2. **Return Value:** The function prints "Hello" and then **returns a reference to the stream itself (`std::cout`)**.
3. **Chaining:** Because it returns the stream, the statement simplifies to: `std::cout << " World";`.
4. **Continuation:** The next part of the chain can now execute using that same stream.

If your operator overload returned `void` instead of `std::ostream&`, the chain would break at step 2, resulting in a compilation error (e.g., `void << " World";`).

## 4. What is `std::endl`?
`std::endl` is **not** a character or a string—it is a **function** (specifically, an I/O manipulator). 

When you write `std::cout << std::endl;`:
1. The compiler finds a special `operator<<` inside the `std::ostream` class that is designed specifically to accept function pointers.
2. It passes `std::cout` (itself) as an argument to the `std::endl` function.
3. The `std::endl` function inserts a newline character (`\n`) and then calls `os.flush()`.

### Performance Note: `\n` vs `std::endl`
Calling `.flush()` forces the operating system to immediately push the buffer to the console, which is computationally expensive. In competitive programming, outputting hundreds of thousands of lines under a strict time limit using `std::endl` will almost certainly cause a "Time Limit Exceeded" (TLE) error. Always use `\n` for fast I/O, as it adds a newline to the buffer without forcing a slow flush.