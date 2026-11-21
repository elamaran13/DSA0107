# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 04: Control Implicit Conversions

### 1. Predict the Output Analysis
Before running:
- `int a = 7, b = 2; double c = a / b;` -> `a / b` evaluates as integer division `3`. Assigned to double `c` becomes `3` (printed as `3`).
- `static_cast<double>(a) / b` -> `7.0 / 2` evaluates to floating-point division `3.5`.
- `'A' + 2` -> Character literal `'A'` (ASCII 65) + 2 = 67, which is `'C'`.
- `ch + 1` -> Integral promotion to `int`, prints `68`.
- `bool flag = 5;` -> Any non-zero numeric value converts to `true` (prints `1` or `true`).
- `s < u` -> `s` is signed `-1`, `u` is unsigned `1`. In mixed comparison, `s` is converted to `unsigned int`, becoming `4294967295`. Thus `4294967295 < 1` is false, outputting `"s >= u"`.

### 2. Actual Program Output
```
3 3.5
C 68
1 true
s >= u
```

### 3. Analysis of Conversions & Prevention
- **Signed vs Unsigned**: Comparing signed with unsigned triggers compiler warning `-Wsign-compare` and results in logical inversion bugs (`-1 > 1U`).
- **Narrowing Conversion**: Uniform brace initialization (e.g., `int x{3.7};`) is enforced by modern C++ to generate a compilation error upon loss of precision.
- **Explicit Casting**: Always use `static_cast<double>(a)` rather than C-style casts `(double)a`.

### Output Log
```
3 3.5
C 68
1 true
s >= u

```
