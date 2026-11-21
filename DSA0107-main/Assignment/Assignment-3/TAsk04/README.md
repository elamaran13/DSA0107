# Assignment 3 - CO3: Constructors, Destructors and Operator Overloading
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 04 (Q4): Overloading Arithmetic and Stream Operators

### 1. Implementation of Completed Code
- `TODO 1 (operator+)`: Overloaded as a const member function returning a new `Money` object containing the summed paise (`12075 + 7925 = 20000`).
- `TODO 2 (operator== & operator<<)`:
  - `operator==` returns `true` if underlying paise are identical.
  - Stream insertion `operator<<` implemented as a `friend` function taking `std::ostream&` by reference on the left and `const Money&` on the right, formatting output as `"Rs 200.00"`.

### 2. Output Verification
Expected Output:
```
Rs 200.00
true
```
Actual Output:
```
Rs 200.00
true
```
Matches expected output with 100% precision.

### Output Log
```
Rs 200.00
true

```
