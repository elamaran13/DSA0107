# Assignment 2 - CO2: Functions and Classes in C++
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 02 (Q2): Return by Reference and Its Dangers

### 1. L-Value Reference Semantics
- When a function returns an l-value reference (`int&`), the function call itself acts as an l-value and can appear on the left-hand side of an assignment operator:
  ```cpp
  getHighestMark(marks, n) = 99;
  ```
- This directly updates the underlying array element in-place without auxiliary lookup functions.

### 2. Dangers: Dangling References
- Returning a reference to a local automatic stack variable causes undefined behavior.
- When the function finishes, its stack frame is popped. The returned reference refers to deallocated stack memory. Reading or writing to it causes silent memory corruption or segmentation faults. Compilers emit `-Wreturn-local-addr` warning.

### Output Log
```
Original marks: 78 85 92 64 88 
After getHighestMark(marks, n) = 99: 78 85 99 64 88 

```
