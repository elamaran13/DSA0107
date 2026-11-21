# Assignment 2 - CO2: Functions and Classes in C++
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 03 (Q3): Default Arguments and Function Overloading

### 1. Ambiguity Problem Analysis
- If a developer provides both:
  ```cpp
  double calc(double wt);
  double calc(double wt, bool express = false);
  ```
  A call `calc(2.5)` produces a compilation error: `call of overloaded 'calc(double)' is ambiguous`, because the compiler cannot determine whether to invoke the single-parameter overload or the two-parameter overload with default argument.

### 2. Disambiguation Strategy
- Distinct parameter signatures:
  1. `calculateCharge(int grams, ...)` -> for integer weights in grams.
  2. `calculateCharge(double kg, ...)` -> for fractional weights in kilograms.
  3. `calculateCharge(const Parcel&, ...)` -> for structured parcel objects.
- All default values (`express = false`, `insurance = false`) are positioned strictly right-to-left.

### Output Log
```
Charge for 1500g (standard): Rs 150
Charge for 2.5kg (express, insured): Rs 400
Charge for Parcel (3.0kg, express): Rs 400

```
