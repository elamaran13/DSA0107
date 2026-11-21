# Assignment 4 - CO4: Designing Reusable Class Hierarchies & Pointers
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 05: Pointers to Objects and the this Pointer

### 1. Implementation of Completed Code
- `TODO 1 (Method Chaining)`: `add()` appends items and returns `*this` (reference to current object), enabling fluent method chaining: `c.add(...).add(...).setDiscount(...)`.
- `TODO 2 (Disambiguating Members)`: Member variable has the exact same name as parameter (`discount`). `this->discount = discount;` explicitly scopes the instance variable via the implicit `this` pointer.

### 2. Output Verification
Expected Output:
```
324.00
```
Actual Output:
```
324.00
```
Matches expected specification with 100% precision (`(60 + 120 + 180) * 0.90 = 360 * 0.90 = 324.00`).

### Output Log
```
324.00

```
