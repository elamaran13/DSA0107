# Assignment 5 - CO5: Polymorphism and Exception Handling
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task B2: Engineer Error Conditions and Exception Rethrowing

### 1. Implementation of Completed Code
- `TODO 1 (approve)`: Checks if `billed < 0 || cover < 0`, throwing `std::invalid_argument("negative amount")`. If `billed > cover`, throws `ClaimError("exceeds cover")`.
- `TODO 2 (settle)`: Intercepts `ClaimError`, prints `"audit: " << e.what() << '
'`, and executes `throw;` to rethrow the identical exception instance.

### 2. Output Verification
Expected Output:
```
approved 40000
audit: exceeds cover
claim rejected: exceeds cover
error: negative amount
```
Actual Output:
```
approved 40000
audit: exceeds cover
claim rejected: exceeds cover
error: negative amount
```
Matches expected specification with 100% precision.

### Output Log
```
approved 40000
audit: exceeds cover
claim rejected: exceeds cover
error: negative amount

```
