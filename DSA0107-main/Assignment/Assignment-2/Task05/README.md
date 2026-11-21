# Assignment 2 - CO2: Functions and Classes in C++
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 05 (Q5): Static Members and Arrays of Objects

### 1. Implementation of Completed Code
- `TODO 1`: Evaluates `issued < CAPACITY`. If capacity remains, increments `++issued` and assigns `seat = issued`. Otherwise `seat = 0` (Waiting list).
- `TODO 2`: Static member function `count()` returns `issued`.

### 2. Output Verification
Expected Output:
```
Asha: Seat 1
Bala: Seat 2
Chitra: Seat 3
Dev: Waiting
Issued: 3
```
Actual Output:
```
Asha: Seat 1
Bala: Seat 2
Chitra: Seat 3
Dev: Waiting
Issued: 3
```
Matches expected output with 100% precision.

### 3. Static Members Semantics
- `static int issued` belongs to class `BusTicket` as a whole, residing in global static memory rather than within each instance.
- Static member functions have no `this` pointer and can access only static class variables.

### Output Log
```
Asha: Seat 1
Bala: Seat 2
Chitra: Seat 3
Dev: Waiting
Issued: 3

```
