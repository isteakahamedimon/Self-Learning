
| Pointer                                                                           | Reference                                            |
| --------------------------------------------------------------------------------- | ---------------------------------------------------- |
| It's a variable type that holds the address. It could be an address of a variable | It's an alias(another name) for an existing variable |

```cpp
\\ Pointer Example
int a = 5;
int* b = &a; \\ b holds the address of variable a
			 \\ b is pointing varible a
*b = 6;      \\ Now a = 6
```

```cpp
\\ Reference Example
int a = 5;
int& b = a; \\ b is referencing variable a

b = 6;      \\ Now a = 6
```
