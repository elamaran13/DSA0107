# Assignment 2 - CO2: Functions and Classes in C++
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 06 (Q6): Friend Functions and Inline Functions

### 1. Implementation of Completed Code
- `TODO 1 (minutesBetween)`: Accesses private members `a.h, a.m, b.h, b.m` directly. Converts each to total minutes from midnight and computes `std::abs(totalA - totalB)`. For 9:45 (585 min) and 13:10 (790 min), difference is `205` minutes.
- `TODO 2 (earlier)`: Compares `a.h < b.h` or `(a.h == b.h && a.m < b.m)`. For `earlier(arrival, departure)` (13:10 earlier than 9:45), returns `false`.

### 2. Output Verification
Expected Output:
```
205 false
```
Actual Output:
```
205 false
```
Matches expected output with 100% precision.

### 3. Friend Function Rationale
- Symmetrical binary operations on two objects of the same class (like comparing two `Time` objects) do not naturally belong to one object over another. A friend function treats both operands with complete symmetry without forcing private member variables to be exposed via getters.

### Output Log
```
205 false

```
