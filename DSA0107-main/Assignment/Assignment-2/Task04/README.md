# Assignment 2 - CO2: Functions and Classes in C++
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 04 (Q4): Specifying a Class with an Array Inside It

### 1. Data Encapsulation
- The array `transactions[10]` and transaction counter are declared `private`. If exposed publicly, external code could alter historical banking audit trails, inject fabricated credits/debits, or cause buffer overflows.

### 2. Linear Array Shifting vs Circular Buffer (Complexity Analysis)
- **Linear Array Shifting**: When the 11th transaction arrives, shifting elements left `transactions[i] = transactions[i+1]` takes O(N) operations.
- **Circular Buffer Implementation**: Using a `head` index with modulo indexing `head = (head + 1) % 10` executes insertions in **O(1) time** and zero memory reallocation overhead.

### Output Log
```
=== Mini Statement for Account: SB-100234 ===
Current Balance: Rs 6800
Last Transactions (up to 10):
  1. DR  Rs 500
  2. CR  Rs 200
  3. DR  Rs 100
  4. CR  Rs 150
  5. DR  Rs 250
  6. CR  Rs 300
  7. DR  Rs 50
  8. CR  Rs 400
  9. DR  Rs 150
  10. CR  Rs 800

```
