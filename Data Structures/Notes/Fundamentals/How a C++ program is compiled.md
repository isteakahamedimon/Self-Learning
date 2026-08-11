
## Preprocessing

```
clang++ -E test.cpp test.i
```

```
gcc -E test.cpp test.i
```

```
g++ -E test.cpp test.i
```

In this step, the preprocessor looks for # and it replaces the existing text of the code. 
For example, 
**`#define PI 3.14159`**. Here **`PI`** is replaced by **3.14159** in the code.
`#include<iostream>`. The code of `iostream` replaces the line.

#### Code:

```
#define PI 3.14159

int main() {
 
    std::cout << "Value of PI : " << PI << "\n";

    return 0;
}
```

#### Preprocessed Output

```
# 1 "test.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 513 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "test.cpp" 2


int main() {

    std::cout << "Value of PI : " << 3.14159 << "\n";

    return 0;
}
```


## Compilation

```
clang++ -S test.cpp -o test.s
```

Converts the preprocessed code to its Assembly equivalent. 

## Assembler

Converts assembly code to Machine Code.

## Linking

Combines different .o files

## Loading and Execution
