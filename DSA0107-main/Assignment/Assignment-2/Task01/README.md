# Assignment 2 - CO2: Functions and Classes in C++
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 01 (Q1): Call by Value, by Reference and by Pointer

### 1. Memory and Storage Semantics
- **Call by Value (`long long fee`)**: A distinct copy of the argument is pushed onto the function's activation record (stack frame). Changes affect only this local temporary variable; upon returning, the caller's variable remains unchanged (`45000`).
- **Call by Reference (`long long& fee`)**: An alias is created for the caller's actual variable. No duplicate object is allocated; operations directly mutate the caller's variable (`40500`). Syntactically clean and cannot be null.
- **Call by Pointer (`long long* fee`)**: The memory address of the caller's variable is passed as a value. Requires explicit dereferencing (`*fee`) and null-pointer checking.

### 2. Output Verification
Expected Output:
```
after call by value	: 45000
after call by reference: 40500
```
Actual Output:
```
after call by value	: 45000
after call by reference: 40500
after call by pointer  : 40500
```
Matches expected output exactly.

### Output Log
```
after call by value	: 45000
after call by reference: 40500
after call by pointer  : 40500

```
