
### Reference
Reference is an alias of an existing variable. A reference of a variable is the same variable but with a different name. 

```
#include<iostream>
#include<string>
using namespace std;

int main() {
    int x = 5;
    int& y = x;

    cout << "x:" << x << " y:" << y << "\n";
    cout << "*x:" << &x << " *y:" << &y << "\n";

    return 0;
}

```
```Output
Output:
x:5 y:5
*x:0x16fae69d8 *y:0x16fae69d8

```


### Pointer


# C++ `const` Summary (Objects, Member Functions, and Return Types)

## 1. `const` Object

```cpp
const Person p("Alice");
```

A `const` object **cannot be modified** after it is created.

---

## 2. Member Functions

### Non-`const` member function

```cpp
void setName(string name) {
    m_name = name;
}
```

- May modify the object.
- Can be called **only on non-const objects**.

---

### `const` member function

```cpp
const string& getName() const {
    return m_name;
}
```

The `const` after the parameter list means:

> "This function promises not to modify the object."

Inside a `const` member function:

```cpp
m_name = "Bob";    // ERROR
```

The compiler prevents modifying data members (unless they are `mutable`).

---

## 3. Which Functions Can Be Called?

| Object            | `const` member function | Non-`const` member function |
| ----------------- | ----------------------- | --------------------------- |
| `Person p;`       | ✅ Yes                   | ✅ Yes                       |
| `const Person p;` | ✅ Yes                   | ❌ No                        |

Reason:

- A `non-const` member function **may modify** the object.
- A `const` object must never be modified.
- Therefore, only `const` member functions are allowed.

---

## 4. Two Different `const`s

```cpp
const string& getName() const
```

### First `const`

```cpp
const string&
```

Applies to the **return type**.

Meaning:

- Return a reference.
    
- The caller cannot modify the returned string.
    

```cpp
p.getName() = "Bob";    // ERROR
```

---

### Second `const`

```cpp
getName() const
```

Applies to the **member function**.

Meaning:

- The function cannot modify the object.
    
- It can be called on `const` objects.
    

---

## 5. Returning by Value vs Reference

### Return by value

```cpp
string getName() {
    return m_name;
}
```

Returns a **copy**.

```
m_name  ----copy----> returned object
```

Changing the returned string does not affect `m_name`.

---

### Return by reference

```cpp
string& getName() {
    return m_name;
}
```

Returns an **alias** of `m_name`.

```
m_name <------ returned reference
```

Modifying the returned reference modifies `m_name`.

---

### Return by const reference

```cpp
const string& getName() const {
    return m_name;
}
```

Returns an alias, but read-only.

- No copy.
    
- Caller cannot modify the string.
    
- Function cannot modify the object.
    

This is the standard way to write a getter for large objects like `std::string`.

---

## 6. Reference vs Pointer

Reference (`&`)

```cpp
int x = 10;
int& r = x;
```

- Alias for an existing object.
    
- Cannot be null.
    
- Cannot refer to another object later.
    
- Used like the object itself.
    

Pointer (`*`)

```cpp
int x = 10;
int* p = &x;
```

- Stores an address.
    
- Can be `nullptr`.
    
- Can point somewhere else later.
    
- Must be dereferenced (`*p`) to access the object.
    

---

## 7. Rule to Remember

- **`const` before the function name** → affects the **return value**.
    
- **`const` after the parameter list** → affects the **member function (the object)**.
    

Example:

```cpp
const string& getName() const
```

Read it as:

> "Return a read-only reference to the name, and promise not to modify the object."

---

## 8. Golden Rule

Whenever you write a getter that only reads data, prefer:

```cpp
const T& getSomething() const;
```

It is:

- Efficient (no copy)
    
- Safe (caller can't modify the data)
    
- Usable with both `const` and non-`const` objects